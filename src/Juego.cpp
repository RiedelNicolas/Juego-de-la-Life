#include "Juego.h"

#define VIVA true
#define MUERTA false
#define VIDA_MUERTA 0
#define NACE 'N'
#define MUERE 'M'
#define INFINITO 65535
using namespace std;

Juego::Juego(Tablero* tablero, Grafo* grafo){

	turno = 0 ;
	cantidadDeCelulasNacidas = 0;
	cantidadDeCelulasMuertas= 0;
	cantidadDeCelulasVivas = 0;
	totalCelulasMuertas = 0;
	totalCelulasNacidas = 0;
	this->tablero = tablero;
	this->mallas = tablero->obtenerMallas();
	this->grafo = grafo;
	interfaz = new InterfazDeUsuario();
	impresor = new ImpresorBMP();
}

Juego::~Juego(){
	delete interfaz;
	delete impresor;
}

void Juego::nuevoTurno(){

	int cantidadDeTurnos = interfaz->pedirCantidadDeTurnos();
	ejecutarTurnos(cantidadDeTurnos);
}

void Juego::inicializarJuego(){

	Malla* malla;

	this->turno = 0; //Probar como estaba antes
	interfaz->mensajeDeBienvenida();
	bool ingresarCelulasAdicionales = interfaz->deseaIngresarCelulas();
	mallas->iniciarCursor();

	while(mallas->avanzarCursor()){

		malla = mallas->obtenerCursor();
		impresor->imprimirMalla(malla, turno);
		cantidadDeCelulasNacidas += malla->getCantidadDeCelulasVivas();
		if(ingresarCelulasAdicionales){
			ingresoDeCelulas(malla);
		}
	}
	if(ingresarCelulasAdicionales){
		olvidoAgregarCelulasEnTablero();
	}
	imprimirTablero();
	imprimirResumen();
}

void Juego::imprimirResumen(){

	contarCelulasVivas();
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

void Juego::calcularCaminoMinimo(){

	if(interfaz->deseaCalcularCaminoMinimo()){

		CaminoMinimo caminoMinimo(grafo);

		cout << "Primer tablero (origen). ";
		string nombreMallaOrigen = (interfaz->pedirMallaPorNombre(tablero))->getNombre();
		cout << "Segundo tablero (destino). ";
		string nombreMallaDestino = (interfaz->pedirMallaPorNombre(tablero))->getNombre();

		unsigned int transferenciaMinima = caminoMinimo.calcularTransferenciaMinima(nombreMallaOrigen, nombreMallaDestino);

		if(transferenciaMinima == INFINITO){
			cout << "No hay portales que conecten dichos tableros. No hay transferencia de células.";
		} else {
			cout << "La transferencia mínima de células entre '" << nombreMallaOrigen << "' y '" << nombreMallaDestino
							<< "' es de " << transferenciaMinima << " células." << endl;
		}
	}
}

void Juego::actualizarTablero(){

	cantidadDeCelulasVivas = 0;
	cantidadDeCelulasMuertas = 0;
	cantidadDeCelulasNacidas = 0;
	Malla* malla;

	mallas->iniciarCursor();

	while(mallas->avanzarCursor()){

		malla = mallas->obtenerCursor();
		actualizarMalla(malla);
	}
}

Celula Juego::calcularRestaVidaCelula(Parcela* parcela){

	Celula celula;
	float vidaFinal;
	float vidaInicial = parcela->getCelula()->getVida();
	float vidaARestar = parcela->getVidaARestar();

	vidaFinal = vidaInicial - vidaARestar;

	if(vidaFinal <= 0){
		celula.setEstado(MUERTA);
		celula.setVida(VIDA_MUERTA);
	}
	else{
		celula.setEstado(VIVA);
		celula.setVida(vidaFinal);
		celula.setRgb(parcela->getCelula()->getRgb());
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

void Juego::reemplazarAuxiliar(Celula** auxiliar, Malla* malla){

	for(int i = 0; i < malla->getCantidadDeFilas(); i++){
		for(int j = 0; j < malla->getCantidadDeColumnas(); j++){
			malla->getParcela(i, j)->setCelula(auxiliar[i][j]);
		}
	}
}

void Juego::reducirVidaCelula(Celula* celulaAux, Parcela* parcela){

	*celulaAux = calcularRestaVidaCelula(parcela);
	if(parcela->contienePortal() && !celulaAux->getEstado()){
		parcela->getPortal()->atravesarPortal(parcela, MUERE);
	}
	if(parcela->getCelula()->getEstado() == VIVA  && celulaAux->getEstado() == MUERTA){
		this->cantidadDeCelulasMuertas++;
	}
}

void Juego::hacerNacerCelula(Celula* celulaAux, Parcela* parcela, Rgb* nuevoColorCelula){

	this->cantidadDeCelulasNacidas++;
	celulaAux->setRgb(*nuevoColorCelula);
	celulaAux->setVida(parcela->getVidaAlNacer());

	if(parcela->contienePortal()){

		Portal* portal = parcela->getPortal();
		portal->atravesarPortal(parcela, NACE);

		string entrada = portal->getMallaDeEntrada();
		string salida = portal->getMallaDeSalida();

		Vertice* verticeDeEntrada = grafo->buscarVertice(entrada);
		Vertice* verticeDeSalida = grafo->buscarVertice(salida);
		Arista* arista = verticeDeEntrada->buscarAristaAdyacente(verticeDeSalida);

		grafo->aumentarEnUnoElPeso(arista);
	}
}

void Juego::actualizarMalla(Malla* malla){

	int celulasVivasLindantes;
	int i, j;
	bool estaViva;
	Parcela* parcela = NULL;
	Celula celulaAux;
	Celula** auxiliar = crearAuxiliar(malla);
	Rgb nuevoColorCelula;

	for(i = 0; i < malla->getCantidadDeFilas(); i++){
		for(j = 0; j < malla->getCantidadDeColumnas(); j++){

			celulasVivasLindantes = malla->contarCelulasVivasLindantes(i, j);
			estaViva = malla->getParcela(i, j)->getCelula()->getEstado();
			parcela = malla->getParcela(i, j);

			if((celulasVivasLindantes < 2 || celulasVivasLindantes > 3) && !parcela->getCelula()->nacePorPortal()){
				reducirVidaCelula(&celulaAux, parcela);
			}
			else if(!estaViva && celulasVivasLindantes == 2){
				celulaAux.setEstado(MUERTA);
				celulaAux.setVida(VIDA_MUERTA);
			}
			else{
				celulaAux.setEstado(VIVA);
				if(!estaViva){
					nuevoColorCelula = malla->obtenerColorPromedioDeVecinasVivas(i, j);
					hacerNacerCelula(&celulaAux, parcela, &nuevoColorCelula);
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
	reemplazarAuxiliar(auxiliar, malla);
	destruirAuxiliar(auxiliar, malla);
}

void Juego::imprimirTablero(){
	Malla* malla;
	mallas->iniciarCursor();

	while(mallas->avanzarCursor()){
		malla = mallas->obtenerCursor();
		impresor->imprimirMalla(malla, turno);
	}
}

void Juego::ejecutarTurnos(int cantidadDeTurnos){

	for(int i=0; i<cantidadDeTurnos; i++){
		actualizarTablero();
		turno ++;
		imprimirTablero();
	}
	imprimirResumen();
}

float Juego::calcularPromedio(int numero){

	float promedio;

	if(turno == 0){
		promedio = 0;
	} else{
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
	mallas->iniciarCursor();

	while(mallas->avanzarCursor()){
		malla = mallas->obtenerCursor();
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

		if(!parcela->getEstadoDeCelula()){
			parcela->setEstadoDeCelula(VIVA);
			cantidadDeCelulasNacidas++;
			cantidadDeCelulasVivas++;
		}
		impresor->imprimirMalla(malla, turno);
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
