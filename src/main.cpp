#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
#include "Grafo.h"

using namespace std;

int main(){

	Tablero tablero;
	Grafo grafo;
	Juego elJuegoDeLaVida (&tablero, &grafo);
	char ordenIngresada = REINICIAR;

	try{
		while(ordenIngresada != TERMINAR){

			if(ordenIngresada == REINICIAR){
				tablero.vaciarTablero();
				string ruta = elJuegoDeLaVida.pedirRutaArchivo();
				Inicializador leeArchivo(ruta, &tablero, &grafo);
				elJuegoDeLaVida.inicializarJuego();
			}

			elJuegoDeLaVida.nuevoTurno();
			ordenIngresada = elJuegoDeLaVida.obtenerOrdenPorPantalla();
		}

		elJuegoDeLaVida.calcularCaminoMinimo();

	}catch(string mensaje){
		cout << mensaje << endl;
	}

	cout<< "Game Over."<<endl;
	return 0;
}
