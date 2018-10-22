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


		void modificarEstado(bool);


		float conseguirVida();


		void modificarVida(float);
		//Rgb getColor();
};

#endif /* CELULA_H_ */
