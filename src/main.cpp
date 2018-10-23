#include "Tablero.h"
using namespace std;

int main(){

	Tablero tablero;

	cout << tablero.getCantidadDeCelulasVivas() << endl;

	tablero.~Tablero();

	return 0;
}


