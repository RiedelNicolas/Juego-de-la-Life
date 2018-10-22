#ifndef CELULA_H_
#define CELULA_H_


#include <iostream>

class Celula{
	private:
		bool estaViva;
		float vida;
		//Rgb color;
	public:

		// Post: Se crea una celula muerta y con 0.0 de vida
		Celula();

		// Post: Devuelve un bool que responde a la pregunta "Esta viva?"
		bool saberSiEstaViva();

		//Post: Modifica el parametro "estaViva" y lo cambia por "nuevoEstado'
		void modificarEstado(bool nuevoEstado);

		//Post: Devuelve la vida de la celula
		float conseguirVida();

		//Post: Modifica el parametro "vida" por nueva "nuevaVida"
		void modificarVida(float nuevaVida);


		//Rgb getColor();
};

#endif /* CELULA_H_ */
