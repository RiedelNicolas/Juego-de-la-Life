#include "InterfazDeUsuario.h"

#define SI 'S'
#define NO 'N'
#define TERMINAR 'T'
#define CONTINUAR 'C'
#define REINICIAR 'R'

using namespace std;


InterfazDeUsuario::InterfazDeUsuario(){
}

void InterfazDeUsuario::mensajeDeBienvenida(){
	cout << "..:: Bienvenido al Juego de la Vida 1.0 ::.." << endl;
}

bool InterfazDeUsuario::preguntarPorPantalla(string mensaje){

	char respuesta;

	cout << mensaje << endl;
	cin >> respuesta;
	respuesta = toupper(respuesta);

	while( (respuesta != SI) && (respuesta != NO) ){
		cout << "Error! Ingreso inválido. Intente de nuevo. " << endl << mensaje << endl;
		cin >> respuesta;
		respuesta = toupper(respuesta);
	}
	return(respuesta == SI);
}

bool InterfazDeUsuario::deseaAgregarCelula(){

	return preguntarPorPantalla("¿Desea ingresar una célula? (S/N)");
}

bool InterfazDeUsuario::olvidoIngresarCelulas(){

	return preguntarPorPantalla("¿Olvidó ingresar celulas en un tablero? (S/N)");
}

bool InterfazDeUsuario::deseaIngresarCelulas(){

	return preguntarPorPantalla("¿Además de las cargadas por el archivo, desea ingresar células adicionales en alguno de los tableros?");
}

bool InterfazDeUsuario::deseaCalcularCaminoMinimo(){

	return preguntarPorPantalla("¿Desea calcular la mínima transferencia de células entre dos tableros? (S/N)");
}

Malla* InterfazDeUsuario::pedirMallaPorNombre(Tablero* tablero){

	string nombreMalla;
	cout << "Ingrese el nombre del tablero:" << endl;
	cin >> nombreMalla;

	while(tablero->buscarMalla(nombreMalla) == NULL){
		cout << "Error! Ingreso inválido. Intente de nuevo. " << endl;
		cout << "Ingrese el nombre del tablero:" << endl;
		cin >> nombreMalla;
	}

	return (tablero->buscarMalla(nombreMalla));
}


char InterfazDeUsuario::preguntarEstadoDeJuego(){
	char respuesta;
	cout << "Presione T para terminar, R para reiniciar o C para continuar" << endl;
	cin >> respuesta;
	respuesta = toupper(respuesta);

	if( (respuesta != TERMINAR) && (respuesta != REINICIAR) && (respuesta != CONTINUAR) ){
		cout << "Error! Ingreso inválido. Intente de nuevo. " << endl;
		respuesta = preguntarEstadoDeJuego();
	}

	return respuesta;
}


int InterfazDeUsuario::pedirFila(Malla* malla){
	int fila, filaMax;

	filaMax = malla->getCantidadDeFilas();

	do{
		cout << "Ingrese el numero de fila (1-" << filaMax << ")" << endl;
		cin>>fila;
	}while((fila<1) || (fila > filaMax));

	return (fila-1);
}


int InterfazDeUsuario::pedirColumna(Malla* malla){
	int columna, columnaMax;

	columnaMax = malla->getCantidadDeColumnas();

	do{
		cout << "Ingrese el numero de columna (1-" << columnaMax << ")" << endl;
		cin>>columna;
	}while((columna<1) || (columna > columnaMax));

	return (columna-1);
}


int InterfazDeUsuario::pedirCantidadDeTurnos(){
	int turnos;

	cout <<"Ingrese la cantidad de turnos a ejecutar:";
	cin >> turnos;
	while( !cantidadDeTurnosEsValida(turnos) ){
		cout<< "CANTIDAD DE TURNOS NO VALIDA"<<endl;
		turnos = pedirCantidadDeTurnos();
	}

	return turnos;
}


bool InterfazDeUsuario::cantidadDeTurnosEsValida(int turnos){
	return (turnos > 0) ;
}
