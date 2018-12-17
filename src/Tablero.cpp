#include "Tablero.h"

Tablero::Tablero(){

	mallas = new Lista<Malla*>;
}

Tablero::~Tablero(){
	delete mallas;
}

Lista<Malla*>* Tablero::obtenerMallas(){
	return mallas;
}

void Tablero::vaciarTablero(){

	mallas->vaciarLista();
}

Malla* Tablero::buscarMalla(std::string nombreMalla){

	bool mallaEncontrada = false;
	Malla* mallaADevolver = NULL;
	mallas->iniciarCursor();

	while(mallas->avanzarCursor() && !mallaEncontrada){
		Malla* auxiliar = mallas->obtenerCursor();

			if(!auxiliar->getNombre().compare(nombreMalla)){
				mallaADevolver = auxiliar;
				mallaEncontrada = true;
			}
		}

	return mallaADevolver;
}

