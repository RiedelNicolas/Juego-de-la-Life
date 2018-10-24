#ifndef MALLA_H_
#define MALLA_H_

#include "Parcela.h"
#include <iostream>
class Tablero {

	private:
		std::string nombre;
		int ancho;
		int alto;
		int celulasVivas;
		int celulasVivasTurnoAnterior;
		Parcela** parcelas;

	public:

		// Crea un tablero con un numero de filas y columnas indicadas y cuyo nombre es "nombre"
		Tablero(int filas ,int columnas, std::string nombre);

		// Post: Libera los recursos pedidos
		~Tablero();

		//Post: Devuelve la cantidad de celulas vivas que hay en el tablero
		int getCantidadDeCelulasVivas();

		//Post: Devuelve la cantidad de celulas que nacieron en el ultimo turno
		int getCelulasNacidasEnUltimoTurno();

		//Post: Devuelve la cantidad de celulas que murieron en el ultimo turno
		int getCelulasMuertasEnUltimoTurno();

};

#endif /* TABLERO_H_ */
