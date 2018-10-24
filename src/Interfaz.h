
#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_

#include <iostream>


class Interfaz{
	private:
		bool reinicio;
		bool fin;
	public:


		/*
		 * Post: Crea una interfaz con reinicio y fin en false
		 */
		Interfaz();

		/*
		 * Post: Se ejecutan "cantidadDeTurnos" turnos
		 */
		void ejecutarTurnos(int cantidadDeTurnos);

		/*
		 *Post: cambia "reinicio" a true
		 */
		void reiniciarJuego();

		/*
		 * Post: cambia "fin" a true
		 */
		void finalizarJuego();

	private:
		bool turnoValido(int cantidadDeTurnos);

};



#endif /* SRC_INTERFAZ_H_ */
