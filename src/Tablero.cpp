#include "Tablero.h"

Tablero::Tablero(){

	this->primerElemento = NULL;
	this->tamanio = 0;
	this->cursor = 0;
}

Tablero::~Tablero(){
	this->vaciarTablero();
}

void Tablero::vaciarTablero(){

	Nodo* auxiliar = primerElemento;

		if(!this->tableroVacio()){
			while(auxiliar){
				primerElemento = primerElemento->getSigNodo();
				delete auxiliar;
				auxiliar = primerElemento;
			}
		}
}

bool Tablero::tableroVacio(){

	return (primerElemento == NULL);
}

void Tablero::agregarMalla(Malla* nuevaMalla){

	Nodo* aux = new Nodo(nuevaMalla);
	aux->setSigNodo(primerElemento);
	this->primerElemento = aux;
	this->tamanio++;
}

Malla* Tablero::buscarMalla(std::string nombreMalla){

	bool mallaEncontrada = false;
	Malla* mallaADevolver = NULL;
	Nodo* auxiliar = primerElemento;

	if(primerElemento){
		while(auxiliar && !mallaEncontrada){
			if(!auxiliar->getMalla()->getNombre().compare(nombreMalla)){
				mallaADevolver = auxiliar->getMalla();
				mallaEncontrada = true;
			}
			else{
				auxiliar = auxiliar->getSigNodo();
			}
		}
	}
	return mallaADevolver;
}

int Tablero::getTamanio(){

	return tamanio;
}

void Tablero::iniciarCursor(){

	cursor=NULL;
}

bool Tablero::avanzarCursor(){

	if(cursor == NULL){
		cursor = primerElemento;
	}

	else{
		cursor = cursor->getSigNodo();
	}

	return (cursor != NULL);
}

Malla* Tablero::obtenerCursor(){

	Malla* malla;

	if(cursor!=NULL){
		malla = cursor->getMalla();
	}

	return malla;
}
