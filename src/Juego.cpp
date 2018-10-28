#include "Juego.h"
using namespace std;

Juego::Juego(Tablero* tablero){

	estadoDeJuego = CONTINUAR;
	turno = 0;
	celulasVivasTurnoAnterior = 0;
	cantidadDeCelulasMuertas= 0;
	cantidadDeCelulasVivas = 0;
	totalCelulasMuertas = 0;
	totalCelulasNacidas = 0;
	this->tablero = tablero;
}


void Juego::actualizarTablero(){

	int filas, columnas;
	celulasVivasTurnoAnterior = 0;
	cantidadDeCelulasVivas = 0;
	cantidadDeCelulasMuertas = 0;
	Malla* malla;

	tablero->iniciarCursor();

	while(tablero->avanzarCursor()){

		malla = tablero->obtenerCursor();

		celulasVivasTurnoAnterior += malla->getCantidadDeCelulasVivas();
		filas = malla->getCantidadDeFilas();
		columnas = malla->getCantidadDeColumnas();

		actualizarMalla(filas, columnas, malla);

		cantidadDeCelulasVivas += malla->getCantidadDeCelulasVivas();
		malla->getSiguienteMalla();
	}
}

void Juego::actualizarMalla(int filas, int columnas, Malla* malla){

	int celulasVivasLindantes;
	bool estaViva;

	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			celulasVivasLindantes = malla->contarCelulasVivasLindantes(i, j);
			estaViva = malla->getParcela(i, j)->getEstadoDeCelula();

			if(estaViva && (celulasVivasLindantes<2 || celulasVivasLindantes>3)){
				malla->getParcela(i, j)->reducirVidaDeCelula();
				if(!malla->getParcela(i, j)->getEstadoDeCelula()){
					cantidadDeCelulasMuertas++;
				}
			}
			else if(!estaViva && celulasVivasLindantes==3){
				malla->getParcela(i, j)->setEstadoDeCelula(false);
			}
		}
	}
}

void Juego::nuevoTurno(){

	int cantidadDeTurnos;
	cantidadDeTurnos = pedirCantidadDeTurnos();
	while(!cantidadDeTurnoEsValida(cantidadDeTurnos)){
		cout<< "CANTIDAD DE TURNOS NO VALIDA"<<endl;
		cantidadDeTurnos = pedirCantidadDeTurnos();
	}
	ejecutarTurnos(cantidadDeTurnos);
}

void Juego::reiniciarJuego(){

	estadoDeJuego = REINICIAR;
	turno = 0;
}

void Juego::finalizarJuego(){

	estadoDeJuego = TERMINAR;
}

void Juego::inicializarJuego(){
	//ALGO
}

char Juego::getEstado(){

	return estadoDeJuego;
}

bool Juego::cantidadDeTurnoEsValida(int cantidadDeTurnos){

	return cantidadDeTurnos > 0;
}

int Juego::pedirCantidadDeTurnos(){

	int turno;
	cout <<"Ingrese la cantidad de turnos a ejecutar:";
	cin >> turno;
	return turno;
}

void Juego::ejecutarTurnos(int cantidadDeTurnos){

	for(int i=0; i<cantidadDeTurnos; i++){
		actualizarTablero();
		turno ++;
	}
}

float Juego::calcularPromedio(int numero){
	float promedio;
	if(turno == 0){
		promedio = 0;
	}
	else{
		promedio = float(numero)/float(turno);
	}
	return promedio;
}

bool Juego::tableroCongelado(int celulasNacidas, int celulasMuertas){

	return((celulasNacidas == 0) && (celulasMuertas == 0));
}

void Juego::validarCelulasNegativas(int cantidadDeCelulas){

	if(cantidadDeCelulas < 0){
			cantidadDeCelulas = 0;
		}
}

void Juego :: imprimirResumen(){

	int celulasNacidas = (cantidadDeCelulasVivas - celulasVivasTurnoAnterior);

	cout << "Cantidad de celulas vivas: " << cantidadDeCelulasVivas << endl;

	validarCelulasNegativas(celulasNacidas);
	cout << "Cantidad de celulas nacidas en el último turno: " << celulasNacidas << endl;

	cout << "Cantidad de celulas que murieron en el último turno: " << cantidadDeCelulasMuertas << endl;

	totalCelulasNacidas += celulasNacidas;
	cout << "Promedio de nacimientos a lo largo del juego: " << calcularPromedio(totalCelulasNacidas) << endl;

	totalCelulasMuertas += cantidadDeCelulasMuertas;
	cout << "Promedio de muertes a lo largo del juego: " << calcularPromedio(totalCelulasMuertas) << endl;

	if(tableroCongelado(celulasNacidas, cantidadDeCelulasMuertas)){
		cout << "El juego no se ha congelado" << endl;
	}
	else{
		cout << "El juego se ha congelado" << endl;
	}
}

void Juego::imprimirMalla(Malla* malla){

	int i, j, x, y;
	BMP Imagen;
	std::string nombreMalla = malla->getNombre() + ".bmp";

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

				for(x = 1; x <= ANCHO_CELULA; x++){
					for(y = 1; y <= ALTO_CELULA; y++){
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

