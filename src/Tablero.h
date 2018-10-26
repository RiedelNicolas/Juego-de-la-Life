#ifndef TABLERO_H_
#define TABLERO_H_

#include "Malla.h"
#include "Nodo.h"

class Tablero {

	private:

		Nodo* primerElemento; // Primer elemento de la lista

		unsigned tamanio; // Tamaño de la lista

	public:

	/*
	 * Constructor
	 * Post: Crea una lista vacia con el primer elemento apuntando a NULL;
	 */
	Tablero();

	/*
	 * Destructor
	 * Pre: Lista creada
	 * Post: Libera los recursos utilizados por al lista.
	 */
	~Tablero();

	/*
	 * Pre: Lista creada
	 * Post: Devuelve un bool con la respuesta a la pregunta... El tablero esta vacio??
	 */
	bool tableroVacio();

	/*
	 * Pre: Recibe una malla
	 * Post: Agrega la malla a la lista.
	 */
	void agregarMalla(Malla* nuevaMalla);

	/*
	 * Pre: Recibe un string que tiene que ser el nombre de una de las mallas
	 * Post: Devuelve un puntero a la malla con el nombre "nombreMalla"
	 */
	Malla* buscarMalla(std::string nombreMalla);

	/*
	 * Pre: Lista creada
	 * Post: Devuelve el tamaño de la lista (cantidad de nodos de la lista)
	 */

	int getTamanio();
};

#endif /* TABLERO_H_ */
