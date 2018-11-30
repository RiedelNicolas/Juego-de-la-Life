#include "Grafo.h"

Grafo::Grafo(int dimension){
	cantidadDeVertices = dimension;
	adyacencias = new int[dimension];

	for(int i=0; i<dimension; i++){
		adyacencias[i] = new int[dimension];
	}
}
