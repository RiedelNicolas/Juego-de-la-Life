
#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include <iostream>
#include "Malla.h"

class Interfaz{
	private:

	public:
		/*
		 * Post: Crea una interfaz con reinicio y fin en false
		 */
		Interfaz();

		/*
		 * Post: Devuelve la columna ingresada por el usuario
		 */
		int pedirFila(Malla*);

		/*
		 * Post: Devuelve la columna ingresada por el usuario
		 */
		int pedirColumna(Malla*);

		void imprimirResumen();
};



#endif /* SRC_INTERFAZ_H_ */
