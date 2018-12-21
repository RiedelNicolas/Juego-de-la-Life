#include "ImpresorBMP.h"
using namespace std;

ImpresorBMP::ImpresorBMP() {
}

void ImpresorBMP::establecerColorMallaPorDefecto(BMP* Imagen, Malla* malla){

	for(int i = 0; i < ANCHO_CELULA*malla->getCantidadDeColumnas(); i++){
		for(int j = 0; j < ALTO_CELULA*malla->getCantidadDeFilas(); j++){
			//El color de fondo del tablero es por defecto blanco
			(*Imagen)(i, j) -> Red = 255;
			(*Imagen)(i, j) -> Green = 255;
			(*Imagen)(i, j) -> Blue = 255;
			(*Imagen)(i, j) -> Alpha = 0;
		}
	}
}

void ImpresorBMP::cargarMallaEnImagen(BMP* Imagen, Malla* malla){

	int i, j, x, y;

	for( i = 0; i < malla->getCantidadDeFilas(); i++){
		for(j = 0; j < malla->getCantidadDeColumnas(); j++){

			if(malla->getParcela(i, j)->getCelula()->getEstado()){

				for(x = 0; x < ANCHO_CELULA; x++){
					for(y = 0; y < ALTO_CELULA; y++){
						(*Imagen)(ANCHO_CELULA*j + x, ALTO_CELULA*i + y) -> Red = malla->getParcela(i, j)->getCelula()->getRgb().getRojo();
						(*Imagen)(ANCHO_CELULA*j + x, ALTO_CELULA*i + y) -> Green = malla->getParcela(i, j)->getCelula()->getRgb().getVerde();
						(*Imagen)(ANCHO_CELULA*j + x, ALTO_CELULA*i + y) -> Blue = malla->getParcela(i, j)->getCelula()->getRgb().getAzul();
					}
				}
			}
		}
	}
}

void ImpresorBMP::imprimirMalla(Malla* malla, unsigned turno){

	string turnosString;
	stringstream turnosInt;
	turnosInt << turno;
	turnosString = turnosInt.str();

	BMP Imagen;
	string nombreMalla = malla->getNombre() + " - Turno " + turnosString + ".bmp";

	Imagen.SetSize(ANCHO_CELULA*malla->getCantidadDeColumnas(), ALTO_CELULA*malla->getCantidadDeFilas());

	establecerColorMallaPorDefecto(&Imagen, malla);

	cargarMallaEnImagen(&Imagen, malla);

	Imagen.WriteToFile( nombreMalla.c_str() );
}

ImpresorBMP::~ImpresorBMP() {
}

