/*
 * ElementoFloyd.cpp
 *
 *  Created on: Dec 1, 2018
 *      Author: riedel
 */

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

void ElementoFloyd::setnombreDestino(std::string origenRecibido){
	this->nombreDestino = origenRecibido;
}

std::string ElementoFloyd::getnombreDestino(){
	return this->nombreDestino;
}

ElementoFloyd::~ElementoFloyd() {
	// TODO Auto-generated destructor stub
}

