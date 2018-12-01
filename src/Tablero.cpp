#include "Tablero.h"

Tablero::Tablero(){

	this->primerElemento = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

Tablero::~Tablero(){
	this->vaciarTablero();
}

void Tablero::vaciarTablero(){

	Nodo<Malla>* auxiliar = primerElemento;

	if( !this->tableroVacio() ){
		while(auxiliar){
			primerElemento = primerElemento->getSigNodo();
			delete auxiliar;
			auxiliar = primerElemento;
		}
	}
}

bool Tablero::tableroVacio(){

	return ( primerElemento == NULL );
}

void Tablero::agregarMalla(Malla* nuevaMalla){

	Nodo<Malla>* aux = new Nodo<Malla>(nuevaMalla);
	aux->setSigNodo(primerElemento);
	this->primerElemento = aux;
	this->tamanio++;
}

Malla* Tablero::buscarMalla(std::string nombreMalla){

	bool mallaEncontrada = false;
	Malla* mallaADevolver = NULL;
	Nodo<Malla>* auxiliar = primerElemento;

	if(primerElemento){
		while(auxiliar && !mallaEncontrada){
			if(!auxiliar->getElemento()->getNombre().compare(nombreMalla)){
				mallaADevolver = auxiliar->getElemento();
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

	cursor = NULL;
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
	return cursor->getElemento();
}
