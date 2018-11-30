#include <iostream>
#include "Arista.h"

using namespace std;

Arista::Arista(unsigned int peso, Vertice* adyacente){

	this->peso = peso;
	this->adyacente = adyacente;
	this->siguiente = NULL;

}

Arista* Arista::obtenerSiguiente(){

	return (this->siguiente);
}

Vertice* Arista::obtenerVerticeAdyacente(){

	return (this->adyacente);
}

void Arista::cambiarSiguiente(Arista* nuevoSiguiente){

	this->siguiente = nuevoSiguiente;
}

unsigned int Arista::obtenerPeso(){

	return (this->peso);
}

void Arista::cambiarPeso(unsigned int nuevoPeso){

	this->peso = nuevoPeso;
}




