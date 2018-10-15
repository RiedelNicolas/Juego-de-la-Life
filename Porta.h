#ifndef PORTAL_H_
#define PORTAL_H_


#include <iostream>
#include "Parcela.h"

class Portal{
	private:
		char estado;
		Parcela* parcelaDeEntrada;
		Parcela* parcelaDeSalida;
};



#endif /* PORTAL_H_ */
