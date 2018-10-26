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







//	Agrega un elemento a la lista
//	Pre: Lista creada
//	Post: Agrega un elemento (dentro de un nodo) al final de la lista y aumenta tamanio en 1
	void insertar(int filas ,int columnas, std::string nombre);

//	Obtener cantidad de filas que están en "posicion"
//	Pre: Lista creada y no vacía
//	Post: Devuelve la cantidad de filas que están en "posicion"
	int getCantidadDeFilas(unsigned posicion);

//	Obtener cantidad de columnas que están en "posicion"
//	Pre: Lista creada y no vacía
//	Post: Devuelve la cantidad columnas que están en "posicion"
	int getCantidadDeColumnas(unsigned posicion);

//	Obtener tamaño de la lista
//	Pre: Lista  creada
//	Devuelve tamanio (cantidad de nodos de la lista)
	unsigned getTamanio();
};

#endif /* TABLERO_H_ */
