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
	std::string nombreOrigen;
public:
	ElementoFloyd();
	unsigned getPeso();
	void setPeso(unsigned);
	void setNombreOrigen(std::string);
	std::string getNombreOrigen();
	virtual ~ElementoFloyd();
};

#endif /* SRC_ELEMENTOFLOYD_H_ */
