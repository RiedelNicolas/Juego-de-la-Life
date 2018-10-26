#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <iostream>
#include "Malla.h"

class Nodo {

	private:

		Malla* malla;

		Nodo *sig;

	public:

		/*
		 * Constructor
		 * Pre: Recibe un puntero a Malla
		 * Post: Asigna ese puntero al puntero a malla del Nodo
		 */
		Nodo(Malla* malla);

		/*
		 * Destructor
		 * Post: Libera los recursos utilizados por el Nodo
		 */
		~Nodo();

		/*
		 * Pre: Malla creada
		 * Post: Devuelve un pontero a malla
		 */
		Malla* getMalla();

		/*
		 * Post: Devuelve un puntero al siguiente Nodo, en caso
		 * de que no exista un siguiente Nodo, ese puntero va a ser NULL
		 */
		Nodo* getSigNodo();

		/*
		 * Pre: Recibe un puntero a un Nodo
		 * Post: Asigna ese puntero a Nodo como siguiente Nodo
		 */
		void setSigNodo(Nodo* sig);
};

#endif /* SRC_NODO_H_ */
