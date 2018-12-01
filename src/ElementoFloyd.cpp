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
void ElementoFloyd::setNombreOrigen(std::string origenRecibido){
	this->nombreOrigen = origenRecibido;
}
std::string ElementoFloyd::getNombreOrigen(){
	return this->nombreOrigen;
}

ElementoFloyd::~ElementoFloyd() {
	// TODO Auto-generated destructor stub
}

