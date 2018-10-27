#include "Inicializador.h"

#include <iostream>

#define MALLA "Tablero"
#define PORTAL "Portal"
#define PARCELA "Parcela"


unsigned Archivo::getCantidadDeMallas(){
	return cantidadDeMallas;
}

Tablero* Archivo::getTablero(){
	return tablero;
}

Archivo::Archivo(std::string ruta,Tablero* tablero){
	file.open( ruta.c_str() );
	if( !file.is_open() ){
		throw std::string( "No se pudo abrir el archivo");
	}
	cantidadDeMallas = contarCantidadDeMallas();
	this->tablero = tablero;
	levantarTablero();
}


Archivo::~Archivo(){
	file.close();
	delete  tablero; //ojo al piojo, si cambia de scope se pierde,usar en main.
}

unsigned Archivo::contarCantidadDeMallas(){
	file.seekg(0);/*rewind*/
	std::string palabraAuxiliar;
	unsigned contador = 0;
	while( file >> palabraAuxiliar ){
		if( !palabraAuxiliar.compare(MALLA) ){
			contador++;
		}
	}
	return contador;
}

void Archivo::levantarTablero(){
	file.seekg(0);/*rewind*/
	std::string palabraAuxiliar;
	while( !file.eof() ){
		file>>palabraAuxiliar;
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

void Archivo::levantarMalla(){
	std::string nombre;
	int filas,columnas;
	file>>nombre>>columnas>>filas;
	Malla* malla = new Malla (filas,columnas,nombre) ;
	tablero->agregarMalla(malla);
}

void Archivo::levantarParcela(){
	std::string nombreDeLaMalla;
	float natalidad,mortalidad;
	int x,y;

	file >> nombreDeLaMalla;
	file >> x >> y;
	Rgb color = levantarColor();
	file >> natalidad >> mortalidad;

	Malla* malla = tablero->buscarMalla(nombreDeLaMalla);
	Parcela* parcela = malla->getParcela(y-1,x-1);
	parcela->setRgb(color);
	parcela->setNatalidad(natalidad);
	parcela->setMortalidad(mortalidad);

}

void Archivo ::levantarPortal(){
	std::string nombreDeLaMallaOrigen, nombreDeLaMallaDestino;
	int xOrigen,yOrigen,xDestino,yDestino;
	char tipoDePortal;
	Malla* mallaDestino;
	Malla* mallaOrigen;
	Parcela* parcelaOrigen,parcelaDestino;

	file>>nombreDeLaMallaOrigen>>xOrigen>>yOrigen;
	file>>tipoDePortal;
	file>>nombreDeLaMallaDestino>>xDestino>>yDestino;

	mallaOrigen =  tablero->buscarMalla(nombreDeLaMallaOrigen);
	mallaDestino = tablero->buscarMalla(nombreDeLaMallaDestino);
	parcelaOrigen  = mallaOrigen->getParcela(yOrigen-1,xOrigen-1);
	parcelaDestino = mallaDestino->getParcela(yDestino-1,xDestino-1);

	}


Rgb Archivo::levantarColor(){
	Rgb color;
	int rojo,azul,verde;
	file>>rojo>>verde>>azul;
	color.setRojo(rojo); color.setVerde(verde); color.setAzul(azul);
	return color;
}

