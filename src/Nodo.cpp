#include "Nodo.h"

Nodo::Nodo(Malla* mallaRecibida){
	this->malla = mallaRecibida;
	this->siguiente = NULL;
}

Nodo::~Nodo(){
	delete (this->malla);
}

Malla* Nodo::getMalla(){
	return (this->malla);
}

Nodo* Nodo::getSigNodo(){
	return (this->siguiente);
}

void Nodo::setSigNodo(Nodo* siguienteRecibido){
	this->siguiente = siguienteRecibido;
}
