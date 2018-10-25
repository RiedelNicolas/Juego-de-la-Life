#include "Archivo.h"
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

Archivo::Archivo(std::string ruta){
	file.open( ruta.c_str() );
	if( !file.is_open() ){
		throw std::string( "No se pudo abrir el archivo");
	}
	cantidadDeMallas = contarCantidadDeMallas();
	if(cantidadDeMallas == 0){ /*el archivo estaba vacio*/
		tablero=NULL;
	}
	else{
		tablero=levantarTablero();
	}
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
