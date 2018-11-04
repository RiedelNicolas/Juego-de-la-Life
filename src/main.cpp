#include "Malla.h"
#include "Parcela.h"
#include "Juego.h"
#include "Inicializador.h"
using namespace std;

int main(){

	Tablero tablero;
	try{

<<<<<<< HEAD
		Inicializador leeArchivo( "/home/gonzams/git/Juego-de-la-Life/src/prueba.txt", &tablero);
=======
		Inicializador leeArchivo( "/home/riedel/git/Juego-de-la-Life/src/prueba.txt", &tablero);
>>>>>>> f466f11d295e61d9be93fff3ab39f552b809b106
		Juego elJuegoDeLaVida(&tablero);
		elJuegoDeLaVida.jugar();
	}catch(string mensaje){
		cout << mensaje << endl;
	}
	return 0;
}
