#ifndef PARCELA_H_
#define PARCELA_H_

#include <iostream>
#include "Celula.h"
#include "Portal.h"

class Parcela {

	private:
		float indiceDeNacimiento;
		float indiceDeMortalidad;
		Celula celula;
		Portal* portal;

	public:


		//Post: Crea una parcela con indice de nacimiento "nacimiento" e indice de mortalidad "mortalidad"
		Parcela(float nacimiento, float mortalidad);

		//Post: Retorna el factor de nacimiento
		float getFactorDeNacimiento();

		//Post: Retorna el factor de mortalidad
		float getFactordeMortalidad();

		//Post: Retorno la celula que se haya en la parcela
		Celula getCelula();
};
#endif /* PARCELA_H_ */
