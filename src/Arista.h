
#ifndef SRC_ARISTA_H_
#define SRC_ARISTA_H_

#include "Vertice.h"

class Vertice;

class Arista{

private:

	Arista* siguiente;
	Vertice* adyacente;
	unsigned int peso;

public:

	Arista(unsigned int peso, Vertice* adyacente);

	Arista* obtenerSiguiente();

	Vertice* obtenerVerticeAdyacente();

	void cambiarSiguiente(Arista* nuevoSiguiente);

	unsigned int obtenerPeso();

	void cambiarPeso(unsigned int nuevoPeso);


};




#endif /* SRC_ARISTA_H_ */
