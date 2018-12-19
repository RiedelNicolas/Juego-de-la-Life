
#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_

#include "Arista.h"
#include "Lista.h"
#include <iostream>

class Arista;

class Vertice{

private:

	Vertice* siguiente;
	Lista<Arista*>* adyacentes;
	std::string nombreVertice;

public:
	/*
	 * Post: crea Vertice indicando su nombre
	 */
	Vertice(std::string nombreTablero);

	/*
	 * Post: devuelve el nombre asignado a Vertice
	 */
	std::string obtenerNombreVertice();

	/*
	 * Post: inserta la arista al final de la Lista en tamanio + 1
	 */
	void insertarArista(unsigned int peso, Vertice* destino);

	/*
	 * Post: devuelve la arista adyacente al vertice que se le pasa por parámetro
	 */
	Arista* buscarAristaAdyacente(Vertice* vertice);

	/*
	 * Post: devuelve un bool con la respuesta a la pregunta "¿el vértice es adyacente?"
	 */
	bool esVerticeAdyacente(Vertice* verticeABuscar);

	/*
	 * Post: devuelve una lista de Aristas
	 */
	Lista<Arista*>* obtenerAristas();

    /*
     * Post: libera los recursos asociados a Vertice
     */
	~Vertice();

};


#endif /* SRC_VERTICE_H_ */
