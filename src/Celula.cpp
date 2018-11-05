#include "Celula.h"

Celula::Celula(){

<<<<<<< HEAD
	this->estaViva=false;
	this->vida = 0.0;
=======
	this->estaViva = false;
	this->vida = (0.0);
>>>>>>> ef10a5c4c8782dbe4b63df47f41414ee5aab359a
}

bool Celula::getEstado(){
	return estaViva;
}

void Celula::setEstado(bool nuevoEstado){
	this->estaViva = nuevoEstado;
}

float Celula::getVida(){
	return vida;
}

void Celula::setVida(float nuevaVida){

	if(vidaEsValida(nuevaVida)){
		this->vida = nuevaVida;
	}
	else{
		throw std::string("Vida No Valida");
	}
}

Rgb Celula::getRgb(){
	return color;
}

void Celula::setRgb(Rgb color){
	this->color = color;
}

void Celula::setRojo(int rojo){
	color.setRojo(rojo);
}

void Celula::setVerde(int verde){
	color.setVerde(verde);
}

void Celula::setAzul(int azul){
	color.setAzul(azul);
}

bool Celula::vidaEsValida(float vida){
	return vida >= 0.0;
}
