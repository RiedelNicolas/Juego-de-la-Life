#include "Grafo.h"

Grafo::Grafo(int dimension){
	cantidadDeVertices = dimension;
	adyacencias = new int[dimension];

	for(int i=0; i<dimension; i++){
		adyacencias[i] = new int*[dimension];
	}
}

Grafo::~Grafo(){
	for(int i=0; i<dimension; i++){
		delete[] adyacencias[i];
	}
	delete[] adyacencias;
}
