
#ifndef Inicializador_H_
#define Inicializador_H_
#include <fstream>
#include <iostream>

#include "Malla.h"
#include "Tablero.h"
#include "Rgb.hpp"
#include "Celula.h"
#include "Parcela.h"
#include "Portal.h"

class Inicializador{
	private:
		std::ifstream file;
		std::string ruta;
		//unsigned cantidadDeMallas;
		Tablero* tablero;
	public:
		/*pre: Recibe el path donde esta ubicado el Inicializador en forma de string.
	 	 post : intenta abrir dicha ruta en modo de lectura, en caso que no pueda
	       	   tira una excepcion.*/
		Inicializador(std::string ruta,Tablero*);

		/*post :devuelve la cantidad de tableros que se pudo levantar del Inicializador*/
		unsigned getCantidadDeMallas();

		/*post : devuelve un pointer a tablero, si no habia Inicializadors en el tablero devuelve NULL*/
		 Tablero* getTablero();

		//destructor
		~Inicializador();
	private:
		/*cuenta cuantas veces aparece la palabra "Tablero" en el Inicializador.*/
		unsigned contarCantidadDeMallas();

		void levantarTablero();
		/*levanta una malla del Inicializador , que en el Inicializador se llaman "Tablero".*/
		void levantarMalla();
		void levantarPortal();
		void levantarParcela();
		Rgb  levantarColor();

};

#endif /* Inicializador_H_ */
