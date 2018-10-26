
#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include <iostream>
#include "Malla.h"

class Interfaz{
	private:
		char estadoDeJuego;
		unsigned turno;
	public:
// C = continuar; R=reiniciar; T=terminar
		/*
		 * Post: Crea una interfaz con reinicio y fin en false
		 */
		Interfaz();

		void nuevoTurno();
		/*
		 *Post: cambia el estado del juego a Reiniciar
		 */
		void reiniciarJuego();
		/*
		 * Post: Cambia el estado del juego a Terminar
		 */
		void finalizarJuego();
		/*
		 *Post: Devuelve la fila ingresada por el usuario -1
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
		/*
		 * Post: Valida si la cantidad de turnos a ejecutarse es mayor a 0
		 */
		bool turnoValido(int cantidadDeTurnos);
		/*
		 * Post: Pide una cantidad de turnos al usuario y la devuelve
		 */
		int pedirCantidadDeTurnos();
		/*
		 * Post: Se ejecutan "cantidadDeTurnos" turnos
		 */
		void ejecutarTurnos(int cantidadDeTurnos);
		/*
		 * Post: Devuelve el promedio de "numero" por la cantidad de turnos
		 */
		float calcularPromedio(int numero);
};



#endif /* SRC_INTERFAZ_H_ */
