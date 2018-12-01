#include "ElementoFloyd.h"
#include <climits>

ElementoFloyd::ElementoFloyd() {
	this->peso = UINT_MAX;
}

unsigned ElementoFloyd::getPeso(){
	return this->peso;
}

void ElementoFloyd::setPeso(unsigned pesoIngresado){
	this->peso = pesoIngresado;
}

void ElementoFloyd::setNombreDestino(std::string origenRecibido){
	this->nombreDestino = origenRecibido;
}

std::string ElementoFloyd::getNombreDestino(){
	return this->nombreDestino;
}

ElementoFloyd::~ElementoFloyd() {
	// TODO Auto-generated destructor stub
}

