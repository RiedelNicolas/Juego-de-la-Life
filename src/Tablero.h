#ifndef TABLERO_H_
#define TABLERO_H_

#include "Malla.h"

class Tablero {

private:
	Malla* primerElemento; // primer elemento de la lista
	unsigned tamanio; // tamaño de la lista

public:
//	Constructor
//	Pre: -
//	Post: Construye una lista vacía
	Tablero();

//	Destructor
//	Pre: Lista creada
//	Post: Libera todos los recursos de la lista
	~Tablero();

//	Verifica si la lista esta vacía o no,responde la pregunta.
//	Pre: Lista creada
//	Post: Devuelve verdadero si la lista está vacía, y falso en caso contrario
	bool tableroVacio();

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

//	Obtener nombre de la malla que está en "posicion"
//	Pre: Lista creada y no vacía
//	Post: Devuelve el nombre de la malla que está en "posicion"
	int getNombre(unsigned posicion);

//	Elimina los datos que están en "posicion"
//	Pre: Lista creada y no vacía / 0 < posicion <= tamanio
//	Post: Libera el nodo "Malla" que está en "posicion" (se toma 1 como el primero)
	void eliminarTablero(unsigned posicion);

//	Obtener tamaño de la lista
//	Pre: Lista  creada
//	Devuelve tamanio (cantidad de nodos de la lista)
	unsigned getTamanio();
};

#endif /* TABLERO_H_ */
