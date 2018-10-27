#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
using namespace std;

int main(){

	Tablero tablero;
	string texto = "/home/gonzams/git/Juego-de-la-Life/src/prueba.txt";
	Inicializador leeArchivo( "/home/gonzams/git/Juego-de-la-Life/src/prueba.txt", &tablero);
	cout << "No pasó nada raro." << endl;
	return 0;
}


