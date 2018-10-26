#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Malla.h"

class Juego{
	private:
		int cantidadDeCelulasVivas;
		int celulasVivasTurnoAnterior;
	public:
		/* Pre: el tablero está creado.
		 * Post: Modifica el estado de las células teniendo en cuenta los índices
		 * 		 de natalidad y mortalidad de cada parcela, así como los siguientes preceptos:
		 * 		 Una célula muerta con 3 células vecinas vivas, nace.
		 * 		 Una célula viva con 2 o 3 células vecinas vivas, permanece en ese estado.
		 */
		void actualizarMalla(Tablero* tablero);
};



#endif /* SRC_JUEGO_H_ */
