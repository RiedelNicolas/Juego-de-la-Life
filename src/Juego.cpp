#include "Juego.h"
using namespace std;

Juego::Juego(){
	estadoDeJuego = 'C';
	turno = 0;
	celulasVivasTurnoAnterior = 0;
	cantidadDeCelulasVivas = 0;
}

void Juego::actualizarTablero(Tablero* tablero){
	int filas, columnas;
	celulasVivasTurnoAnterior = 0;
	cantidadDeCelulasVivas = 0;
	Malla* malla = tablero->getMalla();

	while(malla){ //REVISAR CUANDO TABLERO.H ESTÉ TERMINADO

		celulasVivasTurnoAnterior += malla->getCantidadDeCelulasVivas();
		filas = malla->getCantidadDeFilas();
		columnas = malla->getCantidadDeColumnas();

		actualizarMalla(filas, columnas, malla);

		cantidadDeCelulasVivas += malla->getCantidadDeCelulasVivas();
		malla->getSiguienteMalla();
	}
}

void Juego::actualizarMalla(int filas, int columnas, Malla* malla){
	int celulasVivasLindantes;
	bool estaViva;

	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			celulasVivasLindantes = malla->contarCelulasVivasLindantes(i, j);
			estaViva = malla->getParcela(i, j)->getEstadoDeCelula();

			if(estaViva && (celulasVivasLindantes<2 || celulasVivasLindantes>3)){
				malla->getParcela(i, j)->reducirVidaDeCelula();
			}
			else if(!estaViva && celulasVivasLindantes==3){
				malla->getParcela(i, j)->setCelulaNacida();
			}
		}
	}
}


void Juego::nuevoTurno(){
	int cantidadDeTurnos;
	cantidadDeTurnos = pedirCantidadDeTurnos();
	while(!turnoValido(cantidadDeTurnos)){
		cout<< "CANTIDAD DE TURNOS NO VALIDA"<<endl;
		cantidadDeTurnos = pedirCantidadDeTurnos();
	}
	ejecutarTurnos(cantidadDeTurnos);
}

void Juego::reiniciarJuego(){
	estadoDeJuego = 'R';
	turno = 0;
}

void Juego::finalizarJuego(){
	estadoDeJuego = 'T';
}


bool Juego::cantidadDeTurnoEsValida(int cantidadDeTurnos){
	return cantidadDeTurnos > 0;
}

int Juego::pedirCantidadDeTurnos(){
	int turno;
	cout <<"Ingrese la cantidad de turnos a ejecutar:";
	cin >> turno;
	return turno;
}

void Juego::ejecutarTurnos(int cantidadDeTurnos){
	for(int i=0; i<cantidadDeTurnos; i++){
		//EJECUTAR NUEVO TURNO
		turno ++;
	}
}

float Juego::calcularPromedio(int numero){
	float promedio;
	if(turno ==0){
		promedio = 0;
	}
	else{
		promedio = float(numero)/float(turno);
	}
	return promedio;
}


