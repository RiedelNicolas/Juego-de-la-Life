#include "InterfazDeUsuario.h"
#define SI 'S'
#define NO 'N'
using namespace std;


InterfazDeUsuario::InterfazDeUsuario(){
}

void InterfazDeUsuario::mensajeDeBienvenida(){
	cout << "..:: Bienvenido al Juego de la Vida 1.0 ::.." << endl;
	//PODRÍAMOS ROBAR ALGO DEL INFORME PARA PONER ACÁ
}

bool InterfazDeUsuario::deseaAgregarCelula(){
	char respuesta;
	cout << "¿Desea ingresar una célula? (S/N)" << endl;
	cin >> respuesta;
	respuesta = toupper(respuesta);

	if((respuesta != SI) && (respuesta != NO)){
		cout << "Error! Ingreso inválido. Intente de nuevo. ";
		deseaAgregarCelula();
	}

	return (respuesta == SI);
}

int InterfazDeUsuario::pedirFila(Malla* malla){
	int fila, filaMax;

	filaMax = malla->getCantidadDeFilas();
	cout << "Ingrese el numero de fila (1-" << filaMax << ")" << endl;
	cin >> fila;

	if((fila<1) || (fila > filaMax)){
		cout << "Valor fuera del rango. Intente de nuevo. " << endl;
		fila = pedirFila(malla);
	}

	return fila-1;
}

int InterfazDeUsuario::pedirColumna(Malla* malla){
	int columna, columnaMax;

	columnaMax = malla->getCantidadDeColumnas();
	cout << "Ingrese el número de columna (1-" << columnaMax << ")";
	cin >> columna;

	if((columna<1) || (columna > columnaMax)){
		cout << "Valor fuera del rango. Intente de nuevo. " << endl;
		columna = pedirColumna(malla);
	}

	return columna-1;
}

