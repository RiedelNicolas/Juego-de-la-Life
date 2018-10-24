#include "Malla.h"

using namespace  std;

Malla::Malla(int filas, int columnas, string nombre){

	this->nombre = nombre;
	ancho = columnas;
	alto = filas;
	celulasVivas = 0;
	celulasVivasTurnoAnterior = 0;
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

int Malla::getCantidadDeCelulasVivas(){

	celulasVivas = 0;
	Parcela parcela;
	Celula celula;

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){

			parcela = parcelas[i][j];
			celula = parcela.getCelula();

			if(celula.getEstado()){
				celulasVivas++;
			}
		}
	}
	return celulasVivas;
}

