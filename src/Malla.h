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
		int celulasVivasTurnoAnterior;
		Parcela** parcelas;
		Malla* mallaSiguiente;

	public:

		// Crea un Malla con un numero de filas y columnas indicadas y cuyo nombre es "nombre"
		Malla(int filas ,int columnas, std::string nombre);

		// Post: Libera los recursos pedidos
		~Malla();

		/* Pre: Malla creada y nuevaMalla válida.
		 * Post: mallaSiguiente apuntará a nuevaMalla.
		 */
		void setSiguienteMalla(Malla* nuevaMalla);

		/* Pre: Malla creada.
		 * Post: Devuelve el puntero al siguiente nodo.
		 * 		 Si es el último devuelve NULL.
		 */
		Malla* getSiguienteMalla();

		/* Pre: Malla creada.
		 * Post: Responde a la pregunta: ¿Existe una siguiente malla?
		 * 		 Devuelve true si existe, false en caso contrario.
		 */
		bool existeSiguienteMalla();

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

		//Post: Devuelve la cantidad de celulas vivas que hay en el Malla
		int getCantidadDeCelulasVivas();


};

#endif /* Malla_H_ */
