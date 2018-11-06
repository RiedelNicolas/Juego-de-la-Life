#include "Juego.h"
#define VIVA true
#define MUERTA false
#define VIDA_MUERTA 0
#define NACE 'N'
#define MUERE 'M'
using namespace std;

Juego::Juego(Tablero* tablero ){

	turno = 0 ;
	cantidadDeCelulasNacidas = 0;
	cantidadDeCelulasMuertas= 0;
	cantidadDeCelulasVivas = 0;
	totalCelulasMuertas = 0;
	totalCelulasNacidas = 0;
	this->tablero = tablero;
	interfaz = new InterfazDeUsuario();
}


Juego::~Juego(){
	delete interfaz;
}

void Juego::nuevoTurno(){

	int cantidadDeTurnos = interfaz->pedirCantidadDeTurnos();
	ejecutarTurnos(cantidadDeTurnos);
}

void Juego::inicializarJuego(){
	Malla* malla;

	interfaz->mensajeDeBienvenida();
	tablero->iniciarCursor();

	while(tablero->avanzarCursor()){

		malla = tablero->obtenerCursor();
		ingresoDeCelulas(malla);
	}

	this->turno = 0;
	olvidoAgregarCelulasEnTablero();
	imprimirResumen();
}



void Juego::imprimirResumen(){

	cout << "Turno:" << turno << endl;
	cout << "Cantidad de celulas vivas: " << cantidadDeCelulasVivas << endl;

	cout << "Cantidad de celulas nacidas en el último turno: " << cantidadDeCelulasNacidas << endl;

	cout << "Cantidad de celulas que murieron en el último turno: " << cantidadDeCelulasMuertas << endl;

	totalCelulasNacidas += cantidadDeCelulasNacidas;
	cout << "Promedio de nacimientos a lo largo del juego: " << calcularPromedio(totalCelulasNacidas) << endl;

	totalCelulasMuertas += cantidadDeCelulasMuertas;
	cout << "Promedio de muertes a lo largo del juego: " << calcularPromedio(totalCelulasMuertas) << endl;

	if(tableroCongelado(cantidadDeCelulasNacidas, cantidadDeCelulasMuertas)){
		cout << "El juego se ha congelado." << endl << endl;
	}
}

void Juego::imprimirMalla(Malla* malla){

	int i, j, x, y;
	BMP Imagen;
	string nombreMalla = malla->getNombre() + ".bmp";

	Imagen.SetSize(ANCHO_CELULA*malla->getCantidadDeColumnas(), ALTO_CELULA*malla->getCantidadDeFilas());

	for(i = 0; i < ANCHO_CELULA*malla->getCantidadDeColumnas(); i++){
		for(j = 0; j < ALTO_CELULA*malla->getCantidadDeFilas(); j++){
			//El color de fondo del tablero es por defecto blanco
			Imagen(i, j) -> Red = 255;
			Imagen(i, j) -> Green = 255;
			Imagen(i, j) -> Blue = 255;
			Imagen(i, j) -> Alpha = 0;
		}
	}

	for(i = 0; i < malla->getCantidadDeFilas(); i++){
		for(j = 0; j < malla->getCantidadDeColumnas(); j++){

			if(malla->getParcela(i, j)->getCelula()->getEstado()){

				for(x = 0; x < ANCHO_CELULA; x++){
					for(y = 0; y < ALTO_CELULA; y++){
						Imagen(ANCHO_CELULA*j + x, ALTO_CELULA*i + y) -> Red = malla->getParcela(i, j)->getCelula()->getRgb().getRojo();
						Imagen(ANCHO_CELULA*j + x, ALTO_CELULA*i + y) -> Green = malla->getParcela(i, j)->getCelula()->getRgb().getVerde();
						Imagen(ANCHO_CELULA*j + x, ALTO_CELULA*i + y) -> Blue = malla->getParcela(i, j)->getCelula()->getRgb().getAzul();
					}
				}
			}
		}
	}
	Imagen.WriteToFile( nombreMalla.c_str() );
}


void Juego::actualizarTablero(){

	cantidadDeCelulasVivas = 0;
	cantidadDeCelulasMuertas = 0;
	cantidadDeCelulasNacidas = 0;
	Malla* malla;

	tablero->iniciarCursor();

	while(tablero->avanzarCursor()){

		malla = tablero->obtenerCursor();

		actualizarMalla(malla);

		cantidadDeCelulasVivas += malla->getCantidadDeCelulasVivas();
	}
}

Celula Juego::calcularRestaVidaCelula(int fila, int columna, Malla* malla){

	Celula celula;
	float vidaFinal;
	float vidaInicial = malla->getParcela(fila, columna)->getCelula()->getVida();
	float vidaARestar = malla->getParcela(fila, columna)->getVidaARestar();

	vidaFinal = vidaInicial - vidaARestar;

	if(vidaFinal <= 0){
		celula.setEstado(MUERTA);
		celula.setVida(VIDA_MUERTA);
	}
	else{
		celula.setEstado(VIVA);
		celula.setVida(vidaFinal);
		celula.setRgb(malla->getParcela(fila, columna)->getCelula()->getRgb());
	}

	return celula;
}

Celula** Juego::crearAuxiliar(Malla* malla){

	Celula** auxiliar = new Celula* [malla->getCantidadDeFilas()];

	for(int i = 0; i < malla->getCantidadDeFilas(); i++){
		auxiliar[i] = new Celula[malla->getCantidadDeColumnas()];
	}

	return auxiliar;
}

void Juego::destruirAuxiliar(Celula** auxiliar, Malla* malla){

	for(int i = 0; i < malla->getCantidadDeFilas(); i++){
		delete[] auxiliar[i];
	}
	delete[] auxiliar;
}

void Juego::actualizarMalla(Malla* malla){

	int celulasVivasLindantes;
	int i, j;
	bool estaViva;
	Celula celulaAux;
	Celula** auxiliar = crearAuxiliar(malla);

	for(i = 0; i < malla->getCantidadDeFilas(); i++){
		for(j = 0; j < malla->getCantidadDeColumnas(); j++){

			celulasVivasLindantes = malla->contarCelulasVivasLindantes(i, j);
			estaViva = malla->getParcela(i, j)->getCelula()->getEstado();
			Parcela* parcela = malla->getParcela(i, j);

			if((celulasVivasLindantes < 2 || celulasVivasLindantes > 3) && !parcela->getCelula()->nacePorPortal()){
				celulaAux = calcularRestaVidaCelula(i, j, malla);
				if(parcela->contienePortal() && !celulaAux.getEstado()){
						parcela->getPortal()->atravesarPortal(parcela, MUERE);
				}
				if(malla->getParcela(i, j)->getCelula()->getEstado() == VIVA  && celulaAux.getEstado() == MUERTA){
					cantidadDeCelulasMuertas++;
				}
			}
			else if(!estaViva && celulasVivasLindantes == 2 ){
				celulaAux.setEstado(MUERTA);
				celulaAux.setVida(VIDA_MUERTA);
			}
			else{
				celulaAux.setEstado(VIVA);
				if(!estaViva){
					cantidadDeCelulasNacidas++;
					celulaAux.setRgb(malla->obtenerColorPromedioDeVecinasVivas(i, j));
					celulaAux.setVida(parcela->getVidaAlNacer());
					if(parcela->contienePortal()){
						parcela->getPortal()->atravesarPortal(parcela, NACE);
					}
				}
				else{
					celulaAux.setRgb(parcela->getCelula()->getRgb());
					celulaAux.setVida(parcela->getCelula()->getVida());
				}
			}
			parcela->getCelula()->nacioMediantePortal(false);
			auxiliar[i][j] = celulaAux;
		}
	}
	for(i = 0; i < malla->getCantidadDeFilas(); i++){
		for(j = 0; j < malla->getCantidadDeColumnas(); j++){
			malla->getParcela(i, j)->setCelula(auxiliar[i][j]);
		}
	}
	destruirAuxiliar(auxiliar, malla);

}

void Juego::imprimirTablero(){
	Malla* malla;
	tablero->iniciarCursor();

	while(tablero->avanzarCursor()){
		malla = tablero->obtenerCursor();
		imprimirMalla(malla);
	}
}

void Juego::ejecutarTurnos(int cantidadDeTurnos){

	for(int i=0; i<cantidadDeTurnos; i++){
		actualizarTablero();
		turno ++;
	}
	imprimirTablero();
	imprimirResumen();

}

float Juego::calcularPromedio(int numero){

	float promedio;

	if(turno == 0){
		promedio = 0;
	}
	else{
		promedio = ( (float)numero)/ turno ;
	}
	return promedio;
}

bool Juego::tableroCongelado(int celulasNacidas, int celulasMuertas){

	return( (celulasNacidas == 0) && (celulasMuertas == 0) );
}

void Juego::contarCelulasVivas(){
	Malla* malla;
	cantidadDeCelulasVivas = 0;
	tablero->iniciarCursor();

	while(tablero->avanzarCursor()){
		malla = tablero->obtenerCursor();
		cantidadDeCelulasVivas += malla->getCantidadDeCelulasVivas();
	}
}

void Juego::ingresoDeCelulas(Malla* malla){

	int fila, columna;
	Parcela* parcela;
	cout << "Ingreso de células para el tablero '" << malla->getNombre() << "':" << endl;

	while(interfaz->deseaAgregarCelula()){

		fila = interfaz->pedirFila(malla);
		columna = interfaz->pedirColumna(malla);

		parcela = malla->getParcela(fila, columna);
		parcela->setEstadoDeCelula(VIVA);

		imprimirMalla(malla);
	}
}

void Juego::olvidoAgregarCelulasEnTablero(){

	Malla* malla;

	while(interfaz->olvidoIngresarCelulas()){

		malla = interfaz->pedirMallaPorNombre(tablero);
		ingresoDeCelulas(malla);
	}
}

char Juego::obtenerOrdenPorPantalla(){
	return interfaz->preguntarEstadoDeJuego();
}
