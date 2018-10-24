#include "Parcela.h"

Parcela::Parcela(float nacimiento, float mortalidad){

	indiceDeNacimiento = nacimiento;
	indiceDeMortalidad = mortalidad;
	portal = NULL;
}

float Parcela::getFactorDeNacimiento(){
	return indiceDeNacimiento;
}

float Parcela::getFactordeMortalidad(){
	return indiceDeMortalidad;
}

Celula Parcela::getCelula(){
	return celula;
}
