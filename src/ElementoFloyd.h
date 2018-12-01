/*
 * ElementoFloyd.h
 *
 *  Created on: Dec 1, 2018
 *      Author: riedel
 */

#ifndef SRC_ELEMENTOFLOYD_H_
#define SRC_ELEMENTOFLOYD_H_
#include <iostream>
#include <string>

class ElementoFloyd {
private:
	unsigned peso;
	std::string nombreDestino;
public:
	/*post:
	 *  Crea el elemento auxiliar y asigna el peso\coste de la arista que representa en el maximo valor
	 *   posible*/
	ElementoFloyd();
	/*
	 * post: Devuelve el peso/coste de la arista que representa.
	 */
	unsigned getPeso();
	/*
	 *  recibe un valor positivo de peso.
	 * post:Asigna el peso ingresado por el usuario a la representacion de arista.
	 */
	void setPeso(unsigned);
	/*
	 * pre: Recibe un string correctamente formado.
	 * post: Asigna dicho string al nombre del destino que representa la arista.
	 */
	void setNombreDestino(std::string);
	/*
	 * pre:El elemento contiene un string valido.
	 * post:Devuelve del nombre de destino en forma de string
	 */
	std::string getNombreDestino();

	virtual ~ElementoFloyd();
};

#endif /* SRC_ELEMENTOFLOYD_H_ */
