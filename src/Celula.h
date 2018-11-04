#ifndef CELULA_H_
#define CELULA_H_

#include <iostream>
#include "Rgb.hpp"

class Celula{

	private:

		float vida;

		Rgb color;

	public:

		//ver porque
		bool estaViva;

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
		 * Pre "nuevaVida" debe ser mayor o igual 0
		 * Post: Modifica el parametro "vida" por nueva "nuevaVida".
		 */
		void setVida(float nuevaVida);

		/*
		 * Post: Devuelve una clase "Rgb" que contiene la informacion de los colores de la celula
		 */
		Rgb getRgb();

		/*
		 * Pre:Recibe una clase "Rgb" valida
		 * Post: Modifica el parametro "color" que contiene la informacion de los colores de la celula
		 */
		void setRgb(Rgb color);

		/*
		 * Post: Modifican el color especificado  por el parametro pasado.
		 */
		void setRojo(int rojo);
		void setVerde(int verde);
		void setAzul(int azul);

	private:
		/*
		 * Post: verifica si la vida es valida, es decir si esta es mayor o igual a 0
		 */
		bool vidaEsValida(float vida);
};

#endif /* CELULA_H_ */
