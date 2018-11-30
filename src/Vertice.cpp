
#include <iostream>
#include "Vertice.h"

using namespace std;

Vertice::Vertice(std::string nombreTablero){

	this->nombreVertice = nombreTablero;
	this->siguiente = NULL;
	this->adyacente = NULL;
	this->cursor = NULL;
	this->tamanio = 0;
}

Vertice* Vertice::obtenerSiguiente(){

	return (this->siguiente);
}

void Vertice::cambiarSiguiente(Vertice* nuevoSiguiente){

	this->siguiente = nuevoSiguiente;
}

std::string Vertice::obtenerNombreVertice(){

	return this->nombreVertice;
}

void Vertice::insertarArista(unsigned int peso, Vertice* destino){

	Arista* nuevaArista = new Arista(peso, destino);

	if(tamanio == 0){
		adyacente = nuevaArista;

	}else{

		Arista* anterior = this->obtenerArista(tamanio -1);
		nuevaArista->cambiarSiguiente(anterior->obtenerSiguiente());
		anterior->cambiarSiguiente(nuevaArista);
	}
	tamanio ++;
	this->iniciarCursor();
}

Arista* Vertice::buscarAristaAdyacente(Vertice* vertice){

	bool encontrado = false;

	if(!verticeEsAdyacente(vertice)){
		throw std::string("El vertice no es adyacente");
	}

	Arista* aristaBuscada;
	iniciarCursor();
	while(avanzarCursor() && !encontrado){
		Arista* aristaActual = obtenerCursor();
		if(aristaActual->obtenerVerticeAdyacente() == vertice){
			aristaBuscada = aristaActual;
			encontrado = true;
		}
	}

	return aristaBuscada;
}

Arista* Vertice::obtenerArista(unsigned int posicion){

    Arista* actual = this->adyacente;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

Arista* Vertice::obtenerCursor(){

	return this->cursor;
}

void Vertice::iniciarCursor(){

	this->cursor = NULL;
}

bool Vertice::avanzarCursor(){

	if(this->cursor == NULL){
		this->cursor = this->adyacente;

	}else{
		this->cursor = this->cursor->obtenerSiguiente();
	}

	return (this->cursor != NULL);
}

bool Vertice::verticeEsAdyacente(Vertice* vertice){

	iniciarCursor();
	bool esta = false;

	while(avanzarCursor() && !esta){
		Arista* actual = obtenerCursor();
		if(actual->obtenerVerticeAdyacente() == vertice){
			esta = true;
		}
	}
	return esta;
}

Vertice::~Vertice(){

	while(adyacente != NULL){

		Arista* aBorrar = adyacente;
		adyacente = this-> adyacente->obtenerSiguiente();

		delete aBorrar;
	}
}





