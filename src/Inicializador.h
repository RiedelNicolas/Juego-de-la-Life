
#ifndef Inicializador_H_
#define Inicializador_H_

#include <fstream>
#include <iostream>

#include "Malla.h"
#include "Tablero.h"
#include "Celula.h"
#include "Parcela.h"
#include "Portal.h"
#include "Rgb.h"

class Inicializador{

	private:

		std::ifstream file;

		std::string ruta;

		Tablero* tablero;

	public:

		/* Pre: Recibe el path donde esta ubicado el archivo con los datos iniciales y un puntero a Tablero.
		 * Si existe un archivo el mismo debe tener el formato especificado en el manual de usuario.
	 	 * Post : intenta abrir dicha ruta en modo de lectura, en caso que no pueda
	     * tira una excepcion. En caso de que pueda, carga el Tablero con los datos obtenidos
	     */
		Inicializador(std::string ruta,Tablero*);

		//Destructor, devuelve los recursos tomados a el sistema operativo.
		~Inicializador();

	private:

		/*Pre: el archivo fue abierto correctamente y tiene el formato adecuado.
		 * post: Carga los datos del archivo en el Tablero del juego/.
		 */
		void levantarTablero();

		/*pre:Archivo correctamente formado.
		 * post:carga la malla correspondiente con los datos obtenidos del archivo.
		 */
		void levantarMalla();

		/*pre:Archivo correctamente formado.
		 * post:carga el portal correspondiente con los datos obtenidos del archivo.
		 */
		void levantarPortal();

		/*pre:Archivo correctamente formado.
		 * post:carga la parcelacorrespondiente con los datos obtenidos del archivo.
		*/
		void levantarParcela();

		/*pre:Archivo correctamente formado.
		 * post:carga el color correspondiente (en formato RGB) con los datos obtenidos del archivo.
		 */
		Rgb  levantarColor();
};

#endif /* Inicializador_H_ */
