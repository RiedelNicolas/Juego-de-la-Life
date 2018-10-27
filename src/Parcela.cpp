#include "Parcela.h"
#define  NATALIDAD_POR_DEFAULT  1.0
#define  MORTALIDAD_POR_DEFAULT 1.0
Parcela::Parcela(){
	vidaAlNacer = 100 * NATALIDAD_POR_DEFAULT;
	vidaARestar = 100 * MORTALIDAD_POR_DEFAULT;
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

void Parcela::setMortalidad(float nuevaMortalidad){
	vidaARestar= 100*nuevaMortalidad;
}

void Parcela::setNatalidad(float nuevaNatalidad){
	vidaAlNacer=100*nuevaNatalidad;
}

Rgb Parcela::getRgb(){
	return color;
}

void Parcela::setRgb(Rgb color){
	this->color=color;
}

//Esto no estoy seguro si funca, sino hay que hacer un metodo que ande que
// devuelva un puntero a la celula o algo para poder modificar la celula.
Celula* Parcela::getCelula(){
	return (&celula);
}


