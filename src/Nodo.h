#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <iostream>
#include "Malla.h"

class Nodo {

	private:

		Malla* malla;
		Nodo* siguiente;

	public:

		/*
		 * Pre: Recibe un puntero a Malla
		 * Post: Asigna ese puntero al puntero a malla del Nodo
		 */
		Nodo(Malla*);

		/*
		 * Post: Libera los recursos utilizados por el Nodo
		 */
		~Nodo();

		/*
		 * Post: Devuelve un puntero a la malla correspondiente al nodo
		 */
		Malla* getMalla();

		/*
		 * Post: Devuelve un puntero al siguiente Nodo, en caso
		 * de que no exista un siguiente Nodo, ese puntero va a ser NULL */
		Nodo* getSigNodo();

		/*
		 * Pre: Recibe un puntero a un Nodo
		 * Post: Asigna ese puntero a Nodo como siguiente Nodo
		 */
		void setSigNodo(Nodo*);
};

#endif /* SRC_NODO_H_ */
