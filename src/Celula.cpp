#include "Celula.h"

Celula::Celula(){
	estaViva = true;
	vida = 0.0;
}

bool Celula::getEstaViva(){
	return estaViva;
}

void Celula::setEstado(bool nuevoEstado){
	estaViva = nuevoEstado;
}

float Celula::getVida(){
	return vida;
}

void Celula::setVida(float nuevaVida){
	vida = nuevaVida;
}

