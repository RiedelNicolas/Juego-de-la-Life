
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
		Tablero* tablero;
	public:
		/*pre: Recibe el path donde esta ubicado el Inicializador en forma de string y un puntero a Tablero.
	 	 post : intenta abrir dicha ruta en modo de lectura, en caso que no pueda
	       	   tira una excepcion. en caso de que pueda, carga el Tablero con los datos ob*/
		Inicializador(std::string ruta,Tablero*);

		/*post : devuelve un pointer a tablero, si no habia Inicializadors en el tablero devuelve NULL*/
		 Tablero* getTablero();

		//destructor
		~Inicializador();
	private:
		void levantarTablero();
		/*levanta una malla del Inicializador*/
		void levantarMalla();
		void levantarPortal();
		void levantarParcela();
		Rgb  levantarColor();
};

#endif /* Inicializador_H_ */
