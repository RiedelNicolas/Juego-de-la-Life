#ifndef PARCELA_H_
#define PARCELA_H_

#include <iostream>
#include "Celula.h"
#include "Rgb.hpp"
#include "Portal.h"

//explicarle a mariano que hacemos aca
class Portal;

class Parcela {

	private:
		float vidaAlNacer;
		float vidaARestar;
		Celula celula;
		Rgb color;
		Portal* portal;

	public:
		/*
		 * Post: Crea una parcela lista para usarse
		 * con indice de nacimiento "nacimiento" e indice de mortalidad "mortalidad"
		 */
		Parcela();

		/*
		 * Post: Libera los recursos tomados
		 */
		~Parcela();

		/*
		 * Post: Devuelve el estado de la celula que contiene
		 * Dicho estado responde a la pregunta "Esta viva?"
		 */
		bool getEstadoDeCelula();
		/*
		 * Pre: Recibe un bool, indicando si se quiere hacer nacer (true)
		 * o matar (false) a la celula.
		 * Post: si es true : La que contiene celula esta viva y
		 * con una vida de 100 * indiceDeNacimiento
		 * 	ej: Si el indiceDeNacimiento de la parcela es de 0.5 entonces la celula tendra 50 de vida
		 * si es false:	 La celula que contiene esta muerta y con 0.0 de vida
		 */
		void setEstadoDeCelula(bool estado);

		/*
		 * Post: Devuelve "vidaARestar" de la parcela
		 */
		float getVidaARestar();

		/*
		 * Post: Devuelve "vidaAlNacer" de la parcela
		 */
		float getVidaAlNacer();
		/*
		 * Post: Reduce la vida de la celula en 100 * indiceDeMortalidad.
		 * En el caso de que no tuviera vida suficiente para ser reducida,
		 * cambia el estado de la celula a muerta y con vida 0
		 */
		void reducirVidaDeCelula();
		/*
		 *Post: Devuelve el Rgb de la parcela.
		 */
		Rgb getRgb();
		/*
		 *Post: cambia el atributo Rgb de la parcela por "nuevoRgb"
		 */
		void setRgb(Rgb nuevoRgb);
		/*
		 * Post: modifica el indice de natalidad de la parcela por "nuavaNatalidad".
		 */
		void setNatalidad(float nuevaNatalidad);
		/*
		 * Post: modifica el indice de mortalidad de la parcela por "nuevaMortalidad".
		 */
		void setMortalidad(float nuevaMortalidad);

		/*
		 * Post: devuelve la direccion a el portal correspondiente a
		 * dicha parcela. Si el portal no existe lo crea.
		 */
		Portal* getPortal();

		/*
		 * Post: Devuelve un puntero a la celula que contiene la parcela
		 */
		Celula* getCelula();

		/*
		 * Pre: Recibe un tipo de dato "Celula" valido
		 * Post: Cambia la celula por la pasada por parametro
		 */
		void setCelula(Celula nuevaCelula);

		/*
		 * Post: responde a la pregunta: '¿La parcela contiene un portal?'
		 */
		bool contienePortal();

};
#endif /* PARCELA_H_ */
