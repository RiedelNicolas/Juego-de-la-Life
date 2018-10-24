
#include <fstream>
#include <iostream>

#include "Malla.h"

class Archivo{
	private:
		std::ifstream file;
		std::string ruta;
		unsigned cantidadDeTableros;
		Tablero* tableros;

	public:

		/*pre: Recibe el path donde esta ubicado el archivo en forma de string.
	 	 post : intenta abrir dicha ruta en modo de lectura, en caso que no pueda
	       	   tira una excepcion.*/
		Archivo(std::string ruta);

		/*post :devuelve la cantidad de tableros que se pudo levantar del archivo*/
		unsigned getCantidadDeTableros();

		/*post : devuelve la direccion al primer elemento del array de tableros*/
		Tablero* getTableros();

	private:
		/*crea dicho tableros dinamicos y asigna la direccion de memoria correspondiente a el inicio del array a "tableros"*/
		void crearTableros();
};
