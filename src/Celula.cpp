#include "Celula.h"

Celula::Celula(){
	this->estaViva = false;
	this->vida = 0.0;
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
	this->vida = nuevaVida;
}

Color Celula::getColor(){
	return color;
}

void Celula::setColor(Color nuevoColor){
	this->color = nuevoColor;
}

