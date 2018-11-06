#include "Inicializador.h"

#include <iostream>

#define MALLA "Tablero"
#define PORTAL "Portal"
#define PARCELA "Parcela"



Inicializador::Inicializador(std::string ruta,Tablero* tablero){
	file.open( ruta.c_str() );
	if( !file.is_open() ){
		throw std::string( "No se pudo abrir el Inicializador");
	}
	this->tablero = tablero;
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
	}
}

void Inicializador::levantarMalla(){
	std::string nombre;
	int filas,columnas;
	file>>nombre>>columnas>>filas;
	Malla* malla = new Malla (filas,columnas,nombre);
	tablero->agregarMalla(malla);
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

void Inicializador ::levantarPortal(){
	std::string nombreDeLaMallaOrigen, nombreDeLaMallaDestino;
	int xOrigen,yOrigen,xDestino,yDestino;
	char estado;
	Malla* mallaDestino;
	Malla* mallaOrigen;
	Parcela* parcelaOrigen;
	Parcela* parcelaDestino;
	Portal* portal;

	file>>nombreDeLaMallaOrigen>>xOrigen>>yOrigen;
	file>>estado;
	file>>nombreDeLaMallaDestino>>xDestino>>yDestino;

	mallaOrigen =  tablero->buscarMalla(nombreDeLaMallaOrigen);
	mallaDestino = tablero->buscarMalla(nombreDeLaMallaDestino);
	parcelaOrigen  = mallaOrigen->getParcela(yOrigen-1,xOrigen-1);
	parcelaDestino = mallaDestino->getParcela(yDestino-1,xDestino-1);

	portal = ( parcelaOrigen->getPortal() );
	portal->setEstado(estado);
	portal->setEntrada(parcelaOrigen);
	portal->setSalida(parcelaDestino);

	if(estado == ACTIVO ){
		Portal* portalSecundario =parcelaDestino->getPortal();
		portalSecundario->setEstado( ACTIVO );
		portalSecundario->setEntrada(parcelaDestino);
		portalSecundario->setSalida(parcelaOrigen);
	}
}


Rgb Inicializador::levantarColor(){
	Rgb color;
	int rojo,azul,verde;
	file>>rojo>>verde>>azul;
	color.setRojo(rojo); color.setVerde(verde); color.setAzul(azul);
	return color;
}

