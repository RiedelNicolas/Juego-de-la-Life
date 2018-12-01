#include "CaminoMinimo.h"

#define INFINITO 65535

CaminoMinimo::CaminoMinimo(Grafo* grafo){

	this-> grafo = grafo;
	tamanio = grafo->obtenerTamanio();
	elementos = new ElementoFloyd*[tamanio];

	for(unsigned int i=0; i<tamanio; i++){
		elementos[i] = new ElementoFloyd[tamanio];
	}

	grafo->iniciarCursor();

	for(unsigned int i=0; i<tamanio; i++){
		grafo->avanzarCursor();
		Vertice* verticeActual = grafo->obtenerCursor();

		for(unsigned int j=0; j<tamanio; j++){
			elementos[j][i].setNombreDestino(verticeActual->obtenerNombreVertice());
		}
	}

	completarMatriz();
}

CaminoMinimo::~CaminoMinimo(){

	for(unsigned int i=0; i<tamanio; i++){
		delete[] elementos[i];
	}

	delete[] elementos;
}

void CaminoMinimo::completarMatriz(){

	grafo->iniciarCursor();

	for(unsigned int i=0; i<tamanio; i++){
		grafo->avanzarCursor();
		Vertice* verticeActual = grafo->obtenerCursor();
		verticeActual->iniciarCursor();

		while(verticeActual->avanzarCursor()){
			unsigned int j=0;
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

unsigned int CaminoMinimo::calcularTransferenciaMinima(std::string origen, std::string destino){

	unsigned int aux;
	ElementoFloyd elementoBuscado;

	for(unsigned int k = 0; k < tamanio; k++){
		for(unsigned int i = 0; i < tamanio; i++){
			for(unsigned int j = 0; j < tamanio; j++){

				aux = elementos[i][k].getPeso() + elementos[k][j].getPeso();

				if(elementos[i][j].getPeso() > aux) {
					elementos[i][j].setPeso(aux);
				}
			}
		}
	}

	elementoBuscado = buscarElemento(origen, destino);

	return elementoBuscado.getPeso();
}

ElementoFloyd CaminoMinimo::buscarElemento(std::string origen, std::string destino){

	ElementoFloyd buscado;
	unsigned int i=0, j=0;
	bool encontrado = false;

	grafo->iniciarCursor();

	while(grafo->avanzarCursor() && i<tamanio && !encontrado){
		Vertice* verticeActual = grafo->obtenerCursor();

		if(verticeActual->obtenerNombreVertice() == origen){
			while(j<tamanio && !encontrado){
				encontrado = (elementos[i][j].getNombreDestino() == destino);
				j++;
			}
		}
		i++;
	}

	buscado = elementos[i-1][j-1];

	return buscado;
}







