#include "Nodo.h"

Nodo::Nodo(Malla* malla){
	this->malla = malla;
	this->sig = NULL;
}

Nodo::~Nodo(){
}

Malla* Nodo::getMalla(){
	return malla;
}

Nodo* Nodo::getSigNodo(){
	return sig;
}

void Nodo::setSigNodo(Nodo* sig){
	this->sig = sig;
}
