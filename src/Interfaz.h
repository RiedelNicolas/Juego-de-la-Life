
#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include <iostream>


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


	private:
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
