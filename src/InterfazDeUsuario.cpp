#include "InterfazDeUsuario.h"
using namespace std;


Interfaz::Interfaz(){
	filaDeCelula = 0;
	columnaDeCelula = 0;
}

void Interfaz::pedirFila(Malla* malla){
	int filaMax;
	filaMax = malla->getCantidadDeFilas();
	cout << "Ingrese el numero de Fila (1-" << filaMax << ")";
	cin >> filaDeCelula;
}

void Interfaz::pedirColumna(Malla* malla){
	int columnaMax;
	columnaMax = malla->getCantidadDeColumnas();
	cout << "Ingrese el número de Columna (1-" << columnaMax << ")";
	cin >> columnaDeCelula;
}

int Interfaz::getFila(){
	return filaDeCelula;
}

int Interfaz::getColumna(){
	return columnaDeCelula;
}
