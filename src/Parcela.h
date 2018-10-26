#ifndef PARCELA_H_
#define PARCELA_H_

#include <iostream>
#include "Celula.h"
#include "Portal.h"
#include "Rgb.hpp"

class Parcela {

	private:
		float vidaAlNacer;
		float vidaARestar;
		Celula celula;
		Rgb* color;
		Portal* portal;

	public:
		/*
		 * Post: Crea una parcela lista para usarse
		 * con indice de nacimiento "nacimiento" e indice de mortalidad "mortalidad"
		 */
		Parcela(float nacimiento, float mortalidad);

		/*
		 * Post: Devuelve el estado de la celula que contiene
		 * Dicho estado responde a la pregunta "Esta viva?"
		 */
		bool getEstadoDeCelula();
		/*
		 * Post: La que contiene celula esta viva y con una vida de 100 * indiceDeNacimiento
		 * 	ej: Si el indiceDeNacimiento de la parcela es de 0.5 entonces la celula tendra 50 de vida
		 */
		void setCelulaNacida();
		/*
		 * Post: La celula que contiene esta muerta y con 0.0 de vida
		 */
		void setCelulaMuerta();
		/*
		 * Post: Reduce la vida de la celula en 100 * indiceDeMortalidad.
		 * En el caso de que no tuviera vida suficiente para ser reducida,
		 * cambia el estado de la celula a muerta y con vida 0
		 */
		void reducirVidaDeCelula();
		/*
		 *
		 */
		Rgb getRgb();
		/*
		 *
		 */
		void setRojo(int rojo);
		void setVerde(int verde);
		void setAzul(int azul);
};
#endif /* PARCELA_H_ */
