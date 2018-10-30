
#ifndef SRC_INTERFAZDEUSUARIO_H_
#define SRC_INTERFAZDEUSUARIO_H_

#include <iostream>
#include "Malla.h"

class InterfazDeUsuario{
	public:

		InterfazDeUsuario();

		/*
		 * Post: Imprime el mensaje de bienvenida al juego.
		 */
		void mensajeDeBienvenida();

		/*
		 * Post: Devuelve un bool de acuerdo a la respuesta del usuario a
		 * 		 la pregunta "¿Desea ingresar una célula?"
		 */
		bool deseaAgregarCelula();

		/*
		 * Post: Devuelve la fila de la célula ingresada por el usuario.
		 */
		int pedirFila(Malla*);

		/*
		 * Post: Devuelve la columna de la célula ingresada por el usuario.
		 */
		int pedirColumna(Malla*);

		void imprimirResumen();
};



#endif /* SRC_INTERFAZDEUSUARIO_H_ */
