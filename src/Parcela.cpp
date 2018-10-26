#include "Parcela.h"

Parcela::Parcela(float nacimiento, float mortalidad){
	vidaAlNacer = 100 * nacimiento;
	vidaARestar = 100 * mortalidad;
	color = {0};
	portal = NULL;
}

bool Parcela::getEstadoDeCelula(){
	return celula.getEstado();
}

void Parcela::setEstadoDeCelula(bool estado){
	if (estado){
	celula.setEstado(true);
	celula.setVida(vidaAlNacer);
	}else {
		celula.setEstado(false);
		celula.setVida(0.0);
	}
}


void Parcela::reducirVidaDeCelula(){
	float nuevaVida;

	nuevaVida =  celula.getVida()- vidaARestar;
	if (nuevaVida<=0.0){
		setEstadoDeCelula(false);
	}
	else{
		celula.setVida(nuevaVida);
	}
}

Rgb Parcela::getRgb(){
	return color;
}

void Parcela::setRgb(Rgb color){
	this->color=color;
}

