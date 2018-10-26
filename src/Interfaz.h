
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
		 * Post: Devuelve la columna ingresada por el usario - 1
		 */
		int pedirFila(Malla*);

		/*
		 * Post: Devuelve la columna ingresada por el usario - 1
		 */
		int pedirColumna(Malla*);

	private:
		/*
		 * Post: recibe una coordenada y devuelve dicha coordenada - 1
		 */
		int recibirCoordenada();
};



#endif /* SRC_INTERFAZ_H_ */
