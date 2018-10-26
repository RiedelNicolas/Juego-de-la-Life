#include "Interfaz.h"
using namespace std;


Interfaz::Interfaz(){

}

int Interfaz::pedirFila(Malla* n){
	int fila, filaMax;
	filaMax = n->getCantidadDeFilas();
	cout << "Ingrese el numero de Fila (1-" << filaMax << ")";
	cin >> fila;
	return fila-1;
}

int Interfaz::pedirColumna(Malla* n){
	int columna, columnaMax;
	columnaMax = n->getCantidadDeColumnas();
	cout << "Ingrese el número de Columna (1-" << columnaMax << ")";
	cin >> columna;
	return columna-1;
}
