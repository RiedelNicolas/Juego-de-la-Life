#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
using namespace std;

int main(){

	Tablero tablero();
	Inicializador leeArchivo("prueba.txt", &tablero);

	return 0;
}


