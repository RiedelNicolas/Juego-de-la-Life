#include "CaminoMinimo.h"

#define INFINITO 65535

CaminoMinimo::CaminoMinimo(Grafo* grafo){

	tamanio = grafo->obtenerTamanio();
	elementos = new ElementoFloyd*[tamanio];

	for(int i=0; i<tamanio; i++){
		elementos[i] = new ElementoFloyd[tamanio];
	}

	grafo->iniciarCursor();

	for(int i=0; i<tamanio; i++){
		grafo->avanzarCursor();
		Vertice* verticeActual = grafo->obtenerCursor();

		for(int j=0; j<tamanio; j++){
			elementos[j][i].setNombreDestino(verticeActual->obtenerNombreVertice());
		}
	}

	completarMatriz(grafo);
}

CaminoMinimo::~CaminoMinimo(){

	for(int i=0; i<tamanio; i++){
		delete[] elementos[i];
	}

	delete[] elementos;
}

void CaminoMinimo::completarMatriz(Grafo* grafo){

	grafo->iniciarCursor();

	for(int i=0; i<tamanio; i++){
		grafo->avanzarCursor();
		Vertice* verticeActual = grafo->obtenerCursor();
		verticeActual->iniciarCursor();

		while(verticeActual->avanzarCursor()){
			int j=0;
			Arista* aristaActual = verticeActual->obtenerCursor();
			Vertice* verticeAdyacente = aristaActual->obtenerVerticeAdyacente();

			while(verticeAdyacente->obtenerNombreVertice() != elementos[i][j].getNombreDestino()){
				j++;
			}

			elementos[i][j].setPeso(aristaActual->obtenerPeso());

			if(i==j){
				elementos[i][j].setPeso(0);
			}
		}
	}
}

void CaminoMinimo::calcularTransferenciaMinima() {

	int aux;

	for(int k = 0; k < this->tamanio; k++){
		for(int i = 0; i < this->tamanio; i++){
			for(int j = 0; j < this->tamanio; j++){

				aux = elementos[i][k] + elementos[k][j];

				if(elementos[i][j] > aux) {
					elementos[i][j] = aux;
				}
			}
		}
	}
}
