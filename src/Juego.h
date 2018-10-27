#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Malla.h"

#define REINICIAR 'C'
#define TERMINAR 'T'

class Juego{
	private:
		char estadoDeJuego; // C = continuar; R=reiniciar; T=terminar
		unsigned turno;
		int cantidadDeCelulasMuertas;
		int cantidadDeCelulasVivas;
		int totalCelulasMuertas;
		int totalCelulasNacidas;
		int celulasVivasTurnoAnterior;
		Tablero* tablero;

	public:

		Juego(Tablero* tablero);

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
		 * Post: Devuelve el estado del juego
		 */
		char getEstado();
		/*
		 *Post: Inicializa el juego
		 */
		void inicializarJuego();

		void imprimirResumen();

	private:
		/* Pre: el tablero está creado.
		 * Post: Modifica el estado de todas las células del juego teniendo en cuenta los índices
		 * 		 de natalidad y mortalidad de cada parcela, así como los siguientes preceptos:
		 * 		 Una célula muerta con 3 células vecinas vivas, nace.
		 * 		 Una célula viva con 2 o 3 células vecinas vivas, permanece en ese estado.
		 */
		void actualizarTablero();

		/* Pre: -
		*  Post: Modifica el estado de todas las células de una malla teniendo en cuenta los índices
		* 		 de natalidad y mortalidad de cada parcela, así como los siguientes preceptos:
		* 		 Una célula muerta con 3 células vecinas vivas, nace.
		* 		 Una célula viva con 2 o 3 células vecinas vivas, permanece en ese estado.
		*/
		void actualizarMalla(int filas, int columnas, Malla* malla);

		/*
		 * Post: Valida si la cantidad de turnos a ejecutarse es mayor a 0
		 */
		bool cantidadDeTurnoEsValida(int cantidadDeTurnos);
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
		/*
		 * Post: Devuelve un bool con la respuesta a la pregunta "¿El tablero está congelado?"
		 */
		bool tableroCongelado(int celulasNacidas, int celulasMuertas);
};



#endif /* SRC_JUEGO_H_ */
