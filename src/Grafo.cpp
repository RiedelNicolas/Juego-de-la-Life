
#include <iostream>
#include "Grafo.h"

using namespace std;

Grafo::Grafo(){

	vertice = new Lista<Vertice*>;
}

bool Grafo::estaVacio(){

	return (this->vertice == NULL);
}

Vertice* Grafo::buscarVertice(std::string nombreTablero){

	Vertice* verticeActual = NULL;
	vertice->iniciarCursor();
	bool verticeEncontrado = false;

	while(!verticeEncontrado && vertice->avanzarCursor()){

		verticeActual = vertice->obtenerCursor();
		if(verticeActual->obtenerNombreVertice() == nombreTablero){
			verticeEncontrado = true;
		}
	}
	return verticeActual;
}

void Grafo::insertarVertice(std::string verticeAInsertar){

	Vertice* nuevoVertice = new Vertice(verticeAInsertar);

	vertice->agregar(nuevoVertice);
}

void Grafo::insertarArista(std::string origen, std::string destino, unsigned int peso){

	if(!existeVertice(origen) || !existeVertice(destino)){
		throw std::string("Los vertices no existen");

	}else{

		Vertice* verticeDeOrigen = buscarVertice(origen);
		Vertice* verticeDeDestino = buscarVertice(destino);

		if(!(verticeDeOrigen->esVerticeAdyacente(verticeDeDestino))){
			verticeDeOrigen->insertarArista(peso, verticeDeDestino);
		}
	}
}


Grafo::~Grafo(){

	delete vertice;
}

bool Grafo::existeVertice(std::string verticeABuscar){

	vertice->iniciarCursor();
	bool verticeEncontrado = false;

	while(vertice->avanzarCursor() && !verticeEncontrado){

		Vertice* verticeActual = vertice->obtenerCursor();
		if(verticeActual->obtenerNombreVertice() == verticeABuscar){
			verticeEncontrado = true;
		}
	}

	return verticeEncontrado;
}

void Grafo::aumentarEnUnoElPeso(Arista* arista){
	unsigned int pesoNuevo = arista->obtenerPeso();
	pesoNuevo ++;
	arista->cambiarPeso(pesoNuevo);
}

