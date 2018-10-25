#include "Interfaz.h"
using namespace std;

Interfaz::Interfaz(){
	estadoDeJuego = 'C';
}

void Interfaz::nuevoTurno(){
	int cantidadDeTurnos;
	cantidadDeTurnos = pedirCantidadDeTurnos();
	while(not turnoValido(cantidadDeTurnos)){
		cout<< "CANTIDAD DE TURNOS NO VALIDA"<<endl;
		cantidadDeTurnos = pedirCantidadDeTurnos();
	}
	ejecutarTurnos(cantidadDeTurnos);
}

void Interfaz::reiniciarJuego(){
	estadoDeJuego = 'R';
}

void Interfaz::finalizarJuego(){
	estadoDeJuego = 'T';
}

bool Interfaz::turnoValido(int cantidadDeTurnos){
	return cantidadDeTurnos > 0;
}

int Interfaz::pedirCantidadDeTurnos(){
	int turno;
	cout <<"Ingrese la cantidad de turnos a ejecutar:";
	cin >> turno;
	return turno;
}

void Interfaz::ejecutarTurnos(int cantidadDeTurnos){
	for(int i=0; i<cantidadDeTurnos; i++){
		//EJECUTAR NUEVO TURNO
	}
}
