#include "Interfaz.h"
using namespace std;


Interfaz::Interfaz(){
	estadoDeJuego = 'C';
	turno = 0;
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
	turno = 0;
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
		turno ++;
	}
}

float Interfaz::calcularPromedio(int numero){
	float promedio;
	if(turno ==0){
		promedio = 0;
	}
	else{
		promedio = float(numero)/float(turno);
	}
	return promedio;
}




