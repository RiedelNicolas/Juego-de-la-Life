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

			if(ordenIngresada == REINICIAR ){
				tablero.vaciarTablero();
				Inicializador leeArchivo("/home/ezezbogar/git/Juego-de-la-Life/src/prueba2.txt", &tablero);
				elJuegoDeLaVida.inicializarJuego();
			}

			elJuegoDeLaVida.nuevoTurno();
			ordenIngresada = elJuegoDeLaVida.obtenerOrdenPorPantalla();
		}

	}catch(string mensaje){
		cout << mensaje << endl;
	}

	cout<< "Game Over"<<endl;
	return 0;
}
