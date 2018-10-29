
#ifndef SRC_INTERFAZDEUSUARIO_H_
#define SRC_INTERFAZDEUSUARIO_H_

#include <iostream>
#include "Malla.h"

class Interfaz{
	private:
		int filaDeCelula;
		int columnaDeCelula;
	public:

		Interfaz();

		/*
		 * Post: Pide al usuario que ingrese la fila de célula
		 */
		void pedirFila(Malla*);

		/*
		 * Post: Pide al usuario que ingrese la columna de célula
		 */
		void pedirColumna(Malla*);

		/*
		 * Post: Devuelve la fila de la célula ingresada por el usuario.
		 */
		int getFila();

		/*
		 * Post: Devuelve la columna de la célula ingresada por el usuario.
		 */
		int getColumna();

		void imprimirResumen();
};



#endif /* SRC_INTERFAZDEUSUARIO_H_ */
