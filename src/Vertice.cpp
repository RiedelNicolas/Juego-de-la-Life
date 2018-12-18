#include "Vertice.h"

Vertice::Vertice(std::string nombreTablero){

	adyacentes = new Lista<Arista*>;
	this->nombreVertice = nombreTablero;
	this->siguiente = NULL;
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

	adyacentes->agregar(nuevaArista);
}

bool Vertice::esVerticeAdyacente(Vertice* verticeABuscar){

	bool encontrado = false;
	adyacentes->iniciarCursor();

	while(adyacentes->avanzarCursor() && !encontrado){
			Arista* aristaActual = adyacentes->obtenerCursor();
			if(aristaActual->obtenerVerticeAdyacente() == verticeABuscar){
				encontrado = true;
			}
		}
	return encontrado;
}

Arista* Vertice::buscarAristaAdyacente(Vertice* vertice){

	bool encontrado = false;

	if(!esVerticeAdyacente(vertice)){
		throw std::string("El vertice no es adyacente");
	}

	Arista* aristaBuscada;
	adyacentes->iniciarCursor();
	while(adyacentes->avanzarCursor() && !encontrado){
		Arista* aristaActual = adyacentes->obtenerCursor();
		if(aristaActual->obtenerVerticeAdyacente() == vertice){
			aristaBuscada = aristaActual;
			encontrado = true;
		}
	}

	return aristaBuscada;
}

Vertice::~Vertice(){

	delete adyacentes;
}





