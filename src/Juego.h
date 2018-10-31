#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Malla.h"
#include "EasyBMP.h"
#include "InterfazDeUsuario.h"

#define REINICIAR 'R'
#define TERMINAR 'T'
#define CONTINUAR 'C'
#define ANCHO_CELULA 10
#define ALTO_CELULA 10

class Juego{
	private:
		char estadoDeJuego; // 'C': continuar; 'R': reiniciar; 'T': terminar
		unsigned turno;
		int cantidadDeCelulasMuertas;
		int cantidadDeCelulasVivas;
		int totalCelulasMuertas;
		int totalCelulasNacidas;
		int celulasVivasTurnoAnterior;
		Tablero* tablero;
		InterfazDeUsuario* interfaz;

	public:

		Juego(Tablero* tablero);

		~Juego();

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

		/*
		 * Post: imprime el resumen de juego con cada ejecucion de turno
		 */
		void imprimirResumen();

		/*
		 * Pre: Recibe un puntero a malla inicializado
		 * Post: Imprime la malla en una imagen con el formato nombreMalla.bmp
		 */
		void imprimirMalla(Malla* malla);

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

		/*
		 * Post: si "cantidadDeCelulas" es negativa, le asigna 0
		 */
		void validarCelulasNegativas(int &cantidadDeCelulas);

		void contadorCelulasVivas(Malla* malla, int fila, int columna);

		void ingresoDeCelulas(Malla* malla);

		void agregarCelulasEnTablero();
};



#endif /* SRC_JUEGO_H_ */
