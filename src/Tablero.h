#ifndef TABLERO_H_
#define TABLERO_H_

#include <string>
#include "Parcela.h"

class Tablero {

	private:
		std::string nombre;
		int ancho;
		int alto;
		int celulasVivas;
		int celulasVivasTurnoAnterior;
		Parcela* parcelas;

	public:
		Tablero();
		~Tablero();
		int getCantidadDeCelulasVivas();
		int getCelulasNacidasEnUltimoTurno();
		int getCelulasMuertasEnUltimoTurno();

};




#endif /* TABLERO_H_ */
