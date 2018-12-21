#ifndef SRC_INTERFAZDEUSUARIO_H_
#define SRC_INTERFAZDEUSUARIO_H_

#include <iostream>
#include "Malla.h"
#include "Tablero.h"

class InterfazDeUsuario{

	public:
		/*
		 *Post: Crea una interfaz de usuario lista para ser usada
		 */
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

		/*
		 * Post: Pide una cantidad de turnos al usuario y la devuelve
		 */
		int pedirCantidadDeTurnos();

		/*
		 * Post: Devuelve un bool de acuerdo a la respuesta del usuario a
		 * 		 la pregunta "¿Olvido ingresar células en un tablero?"
		 */
		bool olvidoIngresarCelulas();

		/*
		 * Post: Devuelve un bool de acuerdo a la respuesta del usuario a
		 * 		 la pregunta "¿Desea calcular la mínima transferencia de células entre dos tableros?"
		 */
		bool deseaCalcularCaminoMinimo();

		/*
		 * Post: Devuelve un bool de acuerdo a la respuesta del usuario a
		 * 		 la pregunta "¿Desea ingresar celulas en alguno de los tableros?"
		 */

		bool deseaIngresarCelulas();

		/*
		 *Post: Devuelve un puntero a la malla cuyo nombre ingresa el
		 *		usuario
		 */

		Malla* pedirMallaPorNombre(Tablero* tablero);

		/*
		 * Post: Pregunta al usuario si desea continuar, reiniciar o terminar la
		 * ejecucion del juego. Devuelve su respuesta a saber: 'C' continuar;
		 * 'R' reiniciar  o 'T' terminar
		 */
		char preguntarEstadoDeJuego();

		/*
		 * Post: devuelve un string que contiene la ruta del archivo ingresada por el usuario.
		 */
		std::string pedirRuta();


	private:

		/*
		 * Post: Devuelve un bool que responde a la pregunta:
		 * Es "turnos" una cantidad de turnos valida?
		 * Para que una cantidad de turnos sea valida debe ser mayor a 0
	 	 */
		bool cantidadDeTurnosEsValida(int turnos);

		/* Pre:Recibe una pregunta para el usuario.
		 * Post : Muestra dicha pregunta por consola y le da opcion a el usuario de responder S/N, en caso de respuesta
		 * afirmativa devuelve true. En el caso contrario devuelve false. */

		bool preguntarPorPantalla(std::string mensaje);
};

#endif /* SRC_INTERFAZDEUSUARIO_H_ */
