#include "Inicializador.h"

#include <iostream>

#define MALLA "Tablero"
#define PORTAL "Portal"
#define PARCELA "Parcela"
#define CELULA "Celula"
#define PESO_INICIAL 0
#define VIVA true


Inicializador::Inicializador(std::string ruta,Tablero* tablero, Grafo* grafo){
	file.open( ruta.c_str() );
	if( !file.is_open() ){
		throw std::string( "No se pudo abrir el Inicializador");
	}
	this->tablero = tablero;
	this->grafo = grafo;
	levantarTablero();
	file.close();
}


Inicializador::~Inicializador(){
	if(file.is_open() ){
		file.close();
	}
}

void Inicializador::levantarTablero(){
	std::string palabraAuxiliar;
	while( file>>palabraAuxiliar ){
		if( !palabraAuxiliar.compare(MALLA) ){
			levantarMalla();
		}
		else if( !palabraAuxiliar.compare(PORTAL) ){
			levantarPortal();
		}
		else if( !palabraAuxiliar.compare(PARCELA)){
			levantarParcela();
		}
		else if(!palabraAuxiliar.compare(CELULA)){
			levantarCelula();
		}
	}
}

void Inicializador::levantarMalla(){
	std::string nombre;
	int filas,columnas;
	file>>nombre>>columnas>>filas;

	Lista<Malla*>* mallas = tablero->obtenerMallas();
	Malla* malla = new Malla (filas,columnas,nombre);

	mallas->agregar(malla);
	grafo->insertarVertice(nombre);

}

void Inicializador::levantarParcela(){
	std::string nombreDeLaMalla;
	float natalidad,mortalidad;
	int x,y;

	file >> nombreDeLaMalla;
	file >> x >> y;
	Rgb color = levantarColor();
	file >> natalidad >> mortalidad;

	Malla* malla = tablero->buscarMalla(nombreDeLaMalla);
	Parcela* parcela = malla->getParcela(y-1,x-1);

	parcela->getCelula()->setRgb(color);

	parcela->setRgb(color);
	parcela->setNatalidad(natalidad);
	parcela->setMortalidad(mortalidad);

}


void Inicializador::levantarPortal(){
	std::string nombreDeLaMallaOrigen, nombreDeLaMallaDestino;
	int xOrigen,yOrigen,xDestino,yDestino;
	char estado;
	Malla* mallaDestino;
	Malla* mallaOrigen;
	Parcela* parcelaOrigen;
	Parcela* parcelaDestino;

	file>>nombreDeLaMallaOrigen>>xOrigen>>yOrigen;
	file>>estado;
	file>>nombreDeLaMallaDestino>>xDestino>>yDestino;

	mallaOrigen =  tablero->buscarMalla(nombreDeLaMallaOrigen);
	mallaDestino = tablero->buscarMalla(nombreDeLaMallaDestino);
	parcelaOrigen  = mallaOrigen->getParcela(yOrigen-1,xOrigen-1);
	parcelaDestino = mallaDestino->getParcela(yDestino-1,xDestino-1);

	crearPortal(estado, parcelaOrigen, parcelaDestino, nombreDeLaMallaOrigen, nombreDeLaMallaDestino);
	grafo->insertarArista(nombreDeLaMallaOrigen, nombreDeLaMallaDestino, PESO_INICIAL);

	if(estado == ACTIVO){
		crearPortal(estado, parcelaDestino, parcelaOrigen, nombreDeLaMallaOrigen, nombreDeLaMallaDestino);
		grafo->insertarArista(nombreDeLaMallaDestino, nombreDeLaMallaOrigen, PESO_INICIAL);
	}
}

void Inicializador::levantarCelula(){
	int x, y;
	std::string nombreDeLaMalla;
	Malla* malla;

	file >> nombreDeLaMalla;
	file >> x >> y;

	malla = tablero->buscarMalla(nombreDeLaMalla);
	Parcela* parcela = malla->getParcela(y-1,x-1);
	parcela->setEstadoDeCelula(VIVA);
	malla->aumentarEnUnoLasCelulasVivas(); //SE ASUME QUE NO HAY CELULAS REPETIDAS EN EL ARCHIVO. SI QUIEREN PODEMOS IMPLEMENTAR PARA QUE CHEQUEE
}

Rgb Inicializador::levantarColor(){
	Rgb color;
	int rojo,azul,verde;
	file>>rojo>>verde>>azul;
	color.setRojo(rojo); color.setVerde(verde); color.setAzul(azul);
	return color;
}


void Inicializador::crearPortal(char estado, Parcela* parcelaOrigen, Parcela* parcelaDestino,
		                       std::string nombreDeLaMallaOrigen, std::string nombreDeLaMallaDestino){

	Portal* portal = parcelaOrigen->getPortal();
	portal->setEstado(estado);
	portal->setEntrada(parcelaOrigen);
	portal->setSalida(parcelaDestino);
	portal->setMallaDeEntrada(nombreDeLaMallaOrigen);
	portal->setMallaDeSalida(nombreDeLaMallaDestino);
}
