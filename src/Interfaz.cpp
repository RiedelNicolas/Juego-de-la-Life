#include "Interfaz.h"
using namespace std;


Interfaz::Interfaz(){

}

int Interfaz::pedirFila(Malla* n){
	int fila, filaMax;
	filaMax = n->getCantidadDeFilas();
	cout << "Ingrese el numero de Fila";
	fila = recibirCoordenada();
	return fila;
}

int Interfaz::pedirColumna(Malla* n){
	int columna, columnaMax;
	columnaMax = n->getCantidadDeColumnas();
	cout << "Ingrese el numero de Columna";
	columna = recibirCoordenada();
	return columna;
}

int Interfaz::recibirCoordenada(){
	int coordenada;
	cin >> coordenada;
	return coordenada -1;
}
