#ifndef NODO_H_
#define NODO_H_


#include <iostream>
#include "Parcela.h"

class Nodo{
	private:
		int numeroDeFila;
		Nodo* siguienteFila;
		Parcela* primeraColumna;
	public:
		Nodo();
		~Nodo();
		Nodo* getSiguienteFila();
		Parcela* getSiguienteColumna(int columna);
};



#endif /* NODO_H_ */
