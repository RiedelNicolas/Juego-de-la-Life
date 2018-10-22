#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>
#include <string>
#include "Parcela.h"

class Tablero {

	private:
		std::string nombre;
		int ancho;
		int alto;
		Parcela parcelas[][];

	public:
		Tablero();
		~Tablero();
		int getCantidadDeCeulasVivas();
		int getCelulasNacidasEnUltimoTurno();
		int getCelulasMuertasEnUltimoTurno();
		int getPromedioNacimientos();
		int getPromedioMuertes();
		bool seCongeloJuego();
};




#endif /* TABLERO_H_ */
