#ifndef TABLERO_H_
#define TABLERO_H_

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
		Tablero(int filas ,int columnas, std::string nombre);
		~Tablero();
		int getCantidadDeCelulasVivas();
		int getCelulasNacidasEnUltimoTurno();
		int getCelulasMuertasEnUltimoTurno();

};

#endif /* TABLERO_H_ */
