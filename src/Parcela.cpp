#include "Parcela.h"

Parcela::Parcela(){

	this->indiceDeNacimiento = 0.0;
	this->indiceDeMortalidad = 0.0;
	this->portal = NULL;
	this->celula = NULL;
}

float Parcela::getFactorDeNacimiento(){
	return this->indiceDeNacimiento;
}

float Parcela::getFactordeMortalidad(){
	return this->indiceDeMortalidad;
}

Celula* Parcela::getCelula(){
	return this->celula;
}
