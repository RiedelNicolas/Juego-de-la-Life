#include "Malla.h"

using namespace std;

Malla::Malla(int filas, int columnas, string nombre){

	this->nombre = nombre;
	ancho = columnas;
	alto = filas;
	celulasVivas = 0;
	parcelas = new Parcela*[alto];

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

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){

			if(parcelas[i][j].getEstadoDeCelula()){
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
			if(posicionValida(fila+i,columna+j) && parcelas[fila+i][columna+j].getEstadoDeCelula()){
				contadorCelulasVivas++;
			}
		}
	}

	if(parcelas[fila][columna].getEstadoDeCelula()){
		contadorCelulasVivas--;
	}
	//cout << fila << ", " << columna << ": "<< contadorCelulasVivas << endl;
	return contadorCelulasVivas;
}

bool Malla::posicionValida(int fila, int columna){
	return ((fila >= 0) && (fila < alto) && (columna >= 0) && (columna < ancho));
}
