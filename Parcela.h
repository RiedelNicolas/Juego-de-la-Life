#ifndef PARCELA_H_
#define PARCELA_H_

#include <iostream>
#include "Celula.h"
#include "Portal.h"

class Parcela {
	private:
		int numeroDeColumna;
		float indiceDeNacimiento;
		float indiceDeMortalidad;
		Celula celula;
		Portal* portal;

	public:
		Parcela();
		~Parcela();
		float getFactorDeNacimiento();
		float getFactordeMortalidad();
};




#endif /* PARCELA_H_ */
