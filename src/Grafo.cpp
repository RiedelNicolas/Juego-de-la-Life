
#include <iostream>
#include "Grafo2.h"

using namespace std;

Grafo::Grafo(){

	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

bool Grafo::estaVacio(){

	return (this->primero == NULL);
}

unsigned int Grafo::obtenerTamanio(){

	return (this->tamanio);
}

Vertice* Grafo::buscarVertice(std::string nombreTablero){

	Vertice* verticeActual = NULL;
	iniciarCursor();
	bool verticeEncontrado = false;

	while(!verticeEncontrado && avanzarCursor()){

		verticeActual = obtenerCursor();
		if(verticeActual->obtenerNombreVertice() == nombreTablero){
			verticeEncontrado = true;
		}
	}
	return verticeActual;
}

void Grafo::insertarArista(std::string origen, std::string destino, unsigned int peso){

	if(!existeVertice(origen) || !existeVertice(destino)){
		throw std::string("Los vertices no existen");

	}else{

		Vertice* verticeDeOrigen = buscarVertice(origen);
		Vertice* verticeDeDestino = buscarVertice(destino);

		verticeDeOrigen->insertarArista(peso, verticeDeDestino);
	}
}

void Grafo::insertarVertice(std::string verticeAInsertar){

	Vertice* nuevoVertice = new Vertice(verticeAInsertar);

	if(this->estaVacio()){

		this->primero = nuevoVertice;

	}else{
		Vertice* anterior = this->obtenerVertice(tamanio -1);
		nuevoVertice->cambiarSiguiente(anterior->obtenerSiguiente());
		anterior->cambiarSiguiente(nuevoVertice);
		}

	tamanio ++;
	this->iniciarCursor();
}

void Grafo::iniciarCursor(){

	this->cursor = NULL;
}

bool Grafo::avanzarCursor(){

	if(this->cursor == NULL){
		this->cursor = this->primero;

	}else{
		this->cursor = this->cursor->obtenerSiguiente();
	}

	return (this->cursor != NULL);
}

Vertice* Grafo::obtenerCursor(){

	return this->cursor;
}

bool Grafo::existeVertice(std::string verticeABuscar){

	iniciarCursor();
	bool verticeEncontrado = false;

	while(avanzarCursor() && !verticeEncontrado){

		Vertice* verticeActual = obtenerCursor();
		if(verticeActual -> obtenerNombreVertice() == verticeABuscar){
			verticeEncontrado = true;
		}
	}

	return verticeEncontrado;
}

Vertice* Grafo::obtenerVertice(unsigned int posicion){

	Vertice* actual = this->primero;

	for (unsigned int i = 1; i < posicion; i++) {
		actual = actual->obtenerSiguiente();
	}

	return actual;
}

Grafo::~Grafo(){

	while(primero != NULL){
		Vertice* verticeAEliminar = primero;
		primero = this->primero->obtenerSiguiente();
		delete verticeAEliminar;
	}
}


