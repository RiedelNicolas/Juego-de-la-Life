#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
using namespace std;

int main(){

	Tablero tablero;
	try{
<<<<<<< HEAD
		Inicializador leeArchivo( "/home/ezezbogar/git/Juego-de-la-Life/src/prueba.txt", &tablero);
=======
		Inicializador leeArchivo( "/home/hugo/git/Juego-de-la-Life/src/prueba.txt", &tablero);
>>>>>>> fc8fca996f58657889c340aaa073266b63132525
		Juego elJuegoDeLaVida(&tablero);
		elJuegoDeLaVida.jugar();
	}catch(string mensaje){
		cout << mensaje << endl;
	}
	return 0;
}


