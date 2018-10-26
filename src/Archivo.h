
#ifndef ARCHIVO_H_
#define ARCHIVO_H_
#include <fstream>
#include <iostream>

#include "Malla.h"
#include "Tablero.h"
#include "Rgb.hpp"
#include "Celula.h"

class Archivo{
	private:
		std::ifstream file;
		std::string ruta;
		unsigned cantidadDeMallas;
		Tablero* tablero;
	public:

		/*pre: Recibe el path donde esta ubicado el archivo en forma de string.
	 	 post : intenta abrir dicha ruta en modo de lectura, en caso que no pueda
	       	   tira una excepcion.*/
		Archivo(std::string ruta,Tablero*);

		/*post :devuelve la cantidad de tableros que se pudo levantar del archivo*/
		unsigned getCantidadDeMallas();

		/*post : devuelve un pointer a tablero, si no habia archivos en el tablero devuelve NULL*/
		 Tablero* getTablero();

		//destructor
		~Archivo();
	private:
		/*crea dicho tableros dinamicos y asigna la direccion de memoria correspondiente a el inicio del array a "tableros"*/
		void crearTablero();

		/*cuenta cuantas veces aparece la palabra "Tablero" en el archivo.*/
		unsigned contarCantidadDeMallas();

		void levantarTablero();
		/*levanta una malla del archivo , que en el archivo se llaman "Tablero".*/
		void levantarMalla();
		void levantarPortal();
		void levantarParcela();
};


#endif /* ARCHIVO_H_ */
