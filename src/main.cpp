#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
using namespace std;

int main(){

	Tablero tablero;
	try{
		//string texto = "../prueba.txt";
		Inicializador leeArchivo( "/home/gonzams/git/Juego-de-la-Life/src/prueba.txt", &tablero);
		Juego elJuegoDeLaVida(&tablero);
		elJuegoDeLaVida.inicializarJuego();
		cout << "No pasó nada raro." << endl;
	}catch(string mensaje){
		cout << mensaje << endl;
	}
	return 0;
}


