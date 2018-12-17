#ifndef TABLERO_H_
#define TABLERO_H_

#include "Malla.h"
#include "Lista.h"

class Tablero {

	private:

		Lista<Malla*>* mallas;

	public:

	/*
	 * Post: Crea una lista de tableros vacia con el primer elemento apuntando a NULL;
	 */
	Tablero();

	/*
	 * Pre: Lista creada.
	 * Post: Libera los recursos utilizados por la lista.
	 */
	~Tablero();

	/*
	 * Post: devuelve las mallas que componen el juego.
	 */
	Lista<Malla*>* obtenerMallas();

	/*
	 * Post: Elimina todos los elementos del tablero, devolviendo los recursos al sistema operativo.
	 */
	void vaciarTablero();

	/*
	 * Pre: Recibe un string que tiene que ser el nombre de una de las mallas
	 * Post: Devuelve un puntero a la malla con el nombre "nombreMalla"
	 */
	Malla* buscarMalla(std::string nombreMalla);
};

#endif /* TABLERO_H_ */
