#include "Tablero.h"

Tablero::Tablero(){
	nombre = "boca la concha de tu madre";
	ancho = 20;
	alto = 20;
	celulasVivas = 0;
	celulasVivasTurnoAnterior = 0;
	parcelas = new Parcela[ancho][alto];
}

Tablero::~Tablero(){
	delete []parcelas;
}

int Tablero::getCantidadDeCelulasVivas(){

	celulasVivas = 0;

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){
			if(parcelas[i][j].getCelula()->estaViva()){
				celulasVivas++;
			}
		}
	}
	return celulasVivas;
}

