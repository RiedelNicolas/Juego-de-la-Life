#ifndef CELULA_H_
#define CELULA_H_

#include <iostream>

#include "Rgb.hpp"

class Celula{

	private:
		bool estaViva;
		float vida;
		Rgb* color;

	public:
		/*
		 * Post: Se crea una celula "muerta" y con 0.0 de vida.
		 */
		Celula();
		/*
		 * Post: Devuelve un bool que responde a la pregunta "Esta viva?".
		 */
		bool getEstado();
		/*
		 * Post: Modifica el parametro "estaViva" y lo cambia por "nuevoEstado".
		 */
		void setEstado(bool nuevoEstado);
		/*
		 * Post: Devuelve un float con la vida de la celula.
		 */
		float getVida();
		/*
		 * Post: Modifica el parametro "vida" por nueva "nuevaVida".
		 */
		void setVida(float nuevaVida);
		/*
		 * Post: Devuelve una clase "Rgb" que contiene la informacion de los colores de la celula
		 */
		Rgb getRgb();
		/*
		 * Post: Modifican el color especificado  por el parametro pasado.
		 */
		void setRojo(int rojo);
		void setVerde(int verde);
		void setAzul(int azul);
};

#endif /* CELULA_H_ */
