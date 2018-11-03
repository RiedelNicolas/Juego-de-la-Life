#ifndef MALLA_H_
#define MALLA_H_

#include "Parcela.h"
#include <iostream>
class Malla {

	private:
		std::string nombre;
		int ancho;
		int alto;
		int celulasVivas;
		Parcela** parcelas;

	public:

		// Crea un Malla con un numero de filas y columnas indicadas y cuyo nombre es "nombre"
		Malla(int filas ,int columnas, std::string nombre);

		// Post: Libera los recursos pedidos
		~Malla();

		/* Pre: Malla creada.
		*  Post: Devuelve la cantidad de filas de la malla.
		*/
		int getCantidadDeFilas();

		/* Pre: Malla creada.
		*  Post: Devuelve la cantidad de columnas de la malla.
		*/
		int getCantidadDeColumnas();

		/* Pre: Malla creada.
		*  Post: Devuelve el nombre de la malla.
		*/
		std::string getNombre();

		/*
		 * Post: devuelve un puntero a la parcela en la posición indicada.
		 */
		Parcela* getParcela(int fila,int columna);

		//Post: Devuelve la cantidad de celulas vivas que hay en la Malla
		int getCantidadDeCelulasVivas();

		/* Pre: 'fila' y 'columna' deben ser mayores a 0 y encontrarse dentro de la malla NO TIENE MUCHO SENTIDO ESTA PRE PORQUE EL USUARIO NO METE MANO ACA, LO HACE TODO EL PROGRAMA
 		 * Post: devuelve la cantidad de células vivas alrededor de la célula dentro de la parcela especificada.
		 */
		int contarCelulasVivasLindantes(int fila, int columna);

	private:

		bool posicionValida(int fila, int columna);

};

#endif /* Malla_H_ */
