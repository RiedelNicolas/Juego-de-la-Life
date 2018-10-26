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

Rgb Parcela::getRgb(){
	return color;
}

void Parcela::setRojo(int rojo){
	color->setRojo(rojo);
}
void Parcela::setVerde(int verde){
	color->setVerde(verde);
}
void Parcela::setAzul(int azul){
	color->setAzul(azul);
}
