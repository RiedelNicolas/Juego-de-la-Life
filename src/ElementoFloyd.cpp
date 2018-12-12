#include "ElementoFloyd.h"
#include <climits>
#define INFINITO 65535

ElementoFloyd::ElementoFloyd() {
	this->peso = INFINITO;
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

ElementoFloyd::~ElementoFloyd(){
}

