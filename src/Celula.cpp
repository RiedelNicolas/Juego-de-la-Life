# include <iostream>
#include "Celula.h"

Celula::Celula(){
	estaViva = false;
	vida = 0.0;
}

bool Celula::saberSiEstaViva(){
	return estaViva;
}

void Celula::modificarEstado(bool nuevoEstado){
	estaViva = nuevoEstado;
}


float Celula::conseguirVida(){
	return vida;
}

void Celula::modificarVida(float nuevaVida){
	vida = nuevaVida;
}
