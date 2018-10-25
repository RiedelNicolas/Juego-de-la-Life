#include "Archivo.h"
#include <iostream>

unsigned Archivo::getCantidadDeMallas(){
	return cantidadDeMallas;
}

Malla* Archivo::getMallas(){
	return mallas;
}

Archivo::Archivo(std::string ruta){
	file.open( ruta.c_str() );
	if( !file.is_open() ){
		throw std::string( "No se pudo abrir el archivo");
	}
	cantidadDeMallas = contarCantidadDeMallas();
}


Archivo::~Archivo(){
	file.close();
	delete  mallas; //ojo al piojo, si cambia de scope se pierde,usar en main.
}

//cuento cuantas veces aparece la palabra tablero en el stream.

unsigned Archivo::contarCantidadDeMallas(){
	std::string palabra;
	unsigned contador = 0;
	while( file >> palabra ){
		if(!palabra.compare("Tablero") ){
			contador++;
		}
	}
	return contador;
}
