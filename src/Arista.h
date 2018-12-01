
#ifndef SRC_ARISTA_H_
#define SRC_ARISTA_H_

#include "Vertice.h"
#include <iostream>

class Vertice;

class Arista{

private:

	Arista* siguiente;
	Vertice* adyacente;
	unsigned int peso;

public:

	/*
	 * Post: Arista queda inicializada con su peso, un vértice adyacente y con su siguiente
	 * 		 apuntando a NULL
	 */
	Arista(unsigned int peso, Vertice* adyacente);

	/*
	 * Post: devuelve la siguiente Arista
	 */
	Arista* obtenerSiguiente();

	/*
	 * Post: devuelve el vértice adyacente
	 */
	Vertice* obtenerVerticeAdyacente();

	/*
	 * Post: cambia siguiente Arista por nuevoSiguiente
	 */
	void cambiarSiguiente(Arista* nuevoSiguiente);

	/*
	 * Post: devuelve el peso de la Arista
	 */
	unsigned int obtenerPeso();

	/*
	 * Post: cambia peso Arista por nuevoPeso
	 */
	void cambiarPeso(unsigned int nuevoPeso);


};




#endif /* SRC_ARISTA_H_ */
