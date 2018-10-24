#include "Interfaz.h"
using namespace std;

Interfaz::Interfaz(){
	reinicio = false;
	fin = false;
}

void Interfaz::ejecutarTurnos(int cantidadDeTurnos){
	if(turnoValido(cantidadDeTurnos)){
		for(int i=0; i<cantidadDeTurnos; i++){
			//EJECUTAR NUEVO TURNO
		}
	}
	else{
		cout << "Ingrese una cantidad de turnos validos:" << endl;
		cin << cantidadDeTurnos;
		ejecutarTurnos(cantidadDeTurnos);
	}
}

void Interfaz::reiniciarJuego(){
	reinicio = true;
}

void Interfaz::finalizarJuego(){
	fin = true;
}

bool Interfaz::turnoValido(int cantidadDeTurnos){
	return cantidadDeTurnos > 0;
}


