#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
using namespace std;

int main(){

	Tablero tablero;
	try{

		Inicializador leeArchivo( "/home/gonzams/git/Juego-de-la-Life/src/prueba.txt", &tablero);
//		Inicializador leeArchivo( "/home/hugo/git/Juego-de-la-Life/src/prueba.txt", &tablero);
		Juego elJuegoDeLaVida(&tablero);
		elJuegoDeLaVida.jugar();
	}catch(string mensaje){
		cout << mensaje << endl;
	}
	return 0;
}


