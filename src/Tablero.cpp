#include "Tablero.h"

Tablero::Tablero(){

	this->primerElemento = NULL;
	this->tamanio = 0;
}

Tablero::~Tablero(){

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
	Malla* mallaADevolver;
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




