#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"

using namespace std;

int main(){

	Tablero tablero;
	Juego elJuegoDeLaVida (&tablero);
	char ordenIngresada = REINICIAR;

	try{
		while(ordenIngresada != TERMINAR){

<<<<<<< HEAD
		Inicializador leeArchivo( "/home/hugo/git/Juego-de-la-Life/src/prueba.txt", &tablero);
		Juego elJuegoDeLaVida(&tablero);
		elJuegoDeLaVida.jugar();
=======
			if(ordenIngresada == REINICIAR ){
				tablero.vaciarTablero();
				Inicializador leeArchivo( "/home/riedel/git/Juego-de-la-Life/src/prueba.txt", &tablero);
				elJuegoDeLaVida.inicializarJuego();
			}

			elJuegoDeLaVida.nuevoTurno();
			ordenIngresada = elJuegoDeLaVida.obtenerOrdenPorPantalla();
		}
>>>>>>> c3ec92a0ecac6a1ba8871764bb9976d00bf1ea43

	}catch(string mensaje){
		cout << mensaje << endl;
	}

	cout<< "Game Over"<<endl;
	return 0;
}
