#ifndef SRC_ELEMENTOFLOYD_H_
#define SRC_ELEMENTOFLOYD_H_

#include <iostream>
#include <string>

class ElementoFloyd {

private:

	unsigned peso;
	std::string nombreDestino;

public:

	/*
	 * Post: Crea el elemento auxiliar y asigna el peso\coste de la arista que representa en el maximo valor
	 * posible
	 */
	ElementoFloyd();

	/*
	 * Post: Devuelve el peso/coste de la arista que representa.
	 */
	unsigned getPeso();

	/*
	 * Recibe un valor positivo de peso.
	 * post:Asigna el peso ingresado por el usuario a la representacion de arista.
	 */
	void setPeso(unsigned);

	/*
	 * Pre: Recibe un string correctamente formado.
	 * Post: Asigna dicho string al nombre del destino que representa la arista.
	 */
	void setNombreDestino(std::string);

	/*
	 * Pre:El elemento contiene un string valido.
	 * Post:Devuelve del nombre de destino en forma de string
	 */
	std::string getNombreDestino();

	virtual ~ElementoFloyd();
};

#endif /* SRC_ELEMENTOFLOYD_H_ */
