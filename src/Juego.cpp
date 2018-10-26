#include "Juego.h"

void Juego::actualizarTablero(Tablero* tablero){
	int filas, columnas, celulasVivasLindantes;
	celulasVivasTurnoAnterior = 0;
	cantidadDeCelulasVivas = 0;
	Malla* malla = tablero->getMalla();

	while(malla){ //REVISAR CUANDO TABLERO.H ESTÉ TERMINADO

		celulasVivasTurnoAnterior += malla->getCantidadDeCelulasVivas();
		filas = malla->getCantidadDeFilas();
		columnas = malla->getCantidadDeColumnas();

		actualizarMalla(filas, columnas, malla);

		cantidadDeCelulasVivas += malla->getCantidadDeCelulasVivas();
		malla->getSiguienteMalla();
	}
}

void Juego::actualizarMalla(int filas, int columnas, Malla* malla){

	bool estaViva;

	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			celulasVivasLindantes = malla->contarCelulasVivasLindantes(i, j);
			estaViva = malla->getParcela(i, j)->getEstadoDeCelula();

			if(estaViva && (celulasVivasLindantes<2 || celulasVivasLindantes>3)){
				malla->getParcela(i, j)->reducirVidaDeCelula();
			}
			else if(!estaViva && celulasVivasLindantes==3){
				malla->getParcela(i, j)->setCelulaNacida();
			}
		}
	}
}
