#include "Malla.h"

using namespace std;

Malla::Malla(int filas, int columnas, string nombre){

	this->nombre = nombre;
	ancho = columnas;
	alto = filas;
	celulasVivas = 0;
	parcelas = new Parcela*[alto];
	mallaSiguiente = NULL;

	for(int i = 0; i < alto; i++){
		parcelas[i] = new Parcela[ancho];
	}
}


Malla::~Malla(){

	for(int i = 0; i < alto; i++){
		delete[] parcelas[i];
	}
	delete[] parcelas;
}

void Malla::setSiguienteMalla(Malla* nuevaMalla){
	mallaSiguiente = nuevaMalla;
}

Malla* Malla::getSiguienteMalla(){
	return mallaSiguiente;
}

int Malla::getCantidadDeFilas(){
	return alto;
}

int Malla::getCantidadDeColumnas(){
	return ancho;
}

std::string Malla::getNombre(){
	return nombre;
}

Parcela* Malla::getParcela(int fila,int columna){ //ESTO NO ESTA CHEQUEADO. WARNING!! EXPERIMENTAL.
	return &(parcelas[fila][columna]);
}

int Malla::getCantidadDeCelulasVivas(){

	celulasVivas = 0;
	Parcela parcela;
	bool celulaViva;

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){

			parcela = parcelas[i][j];
			celulaViva = parcela.getEstadoDeCelula();

			if(celulaViva){
				celulasVivas++;
			}
		}
	}
	return celulasVivas;
}

int Malla::contarCelulasVivasLindantes(int fila, int columna){
	int contadorCelulasVivas = 0;

	for(int i=-1; i<2; i++){
			for(int j=-1; j<2; j++){
				if((fila+i >= 0) && (fila+i < alto) && (columna+j >= 0) && (columna+j < ancho)){
					if(parcelas[fila+i][columna+j].getEstadoDeCelula()){
								contadorCelulasVivas++;
					}
				}
			}
		}

		if(parcelas[fila][columna].getEstadoDeCelula()){
			contadorCelulasVivas--;
		}
	return contadorCelulasVivas;
}

