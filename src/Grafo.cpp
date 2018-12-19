
#include <iostream>
#include "Grafo.h"

using namespace std;

Grafo::Grafo(){

	vertices = new Lista<Vertice*>;
}

bool Grafo::estaVacio(){

	return (this->vertices == NULL);
}

Vertice* Grafo::buscarVertice(std::string nombreTablero){

	Vertice* verticeActual = NULL;
	vertices->iniciarCursor();
	bool verticeEncontrado = false;

	while(!verticeEncontrado && vertices->avanzarCursor()){

		verticeActual = vertices->obtenerCursor();
		if(verticeActual->obtenerNombreVertice() == nombreTablero){
			verticeEncontrado = true;
		}
	}
	return verticeActual;
}

void Grafo::insertarVertice(std::string verticeAInsertar){

	Vertice* nuevoVertice = new Vertice(verticeAInsertar);

	vertices->agregar(nuevoVertice);
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

Lista<Vertice*>* Grafo::obtenerVertices(){

	return vertices;
}

Grafo::~Grafo(){

	delete vertices;
}

bool Grafo::existeVertice(std::string verticeABuscar){

	vertices->iniciarCursor();
	bool verticeEncontrado = false;

	while(vertices->avanzarCursor() && !verticeEncontrado){

		Vertice* verticeActual = vertices->obtenerCursor();
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

