#include "Parcela.h"
#define  NATALIDAD_POR_DEFAULT  1.0
#define  MORTALIDAD_POR_DEFAULT 1.0
Parcela::Parcela(){
	vidaAlNacer = 100 * NATALIDAD_POR_DEFAULT;
	vidaARestar = 100 * MORTALIDAD_POR_DEFAULT;
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
void Parcela::setMortalidad(float mortalidad){
	vidaARestar= 100*mortalidad;
}
void Parcela::setNatalidad(float natalidad){
	vidaAlNacer=100*natalidad;
}
Rgb Parcela::getRgb(){
	return color;
}

void Parcela::setRgb(Rgb color){
	this->color=color;
}

