#include "Parcela.h"
#define CIEN 100

Parcela::Parcela(float nacimiento, float mortalidad){

	indiceDeNacimiento = nacimiento;
	indiceDeMortalidad = mortalidad;
	vidaAlNacer = CIEN * indiceDeNacimiento;
	vidaARestar = CIEN* indiceDeMortalidad;
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

bool Parcela::getEstadoDeCelula(){
	return celula.getEstado();
}

void Parcela::setCelulaNacida(){
	celula.setEstado(true);
	celula.setVida(vidaAlNacer);
}

void Parcela::setCelulaMuerta(){
	celula.setEstado(false);
	celula.setVida(0.0);
}

void Parcela::reducirVidaDeCelula(){
	float nuevaVida;

	nuevaVida =  celula.getVida()- vidaARestar;
	if (nuevaVida<=0.0){
		setCelulaMuerta();
	}
	else{
		celula.setVida(nuevaVida);
	}
}
