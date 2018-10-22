#ifndef PORTAL_H_
#define PORTAL_H_


#include <iostream>
#include "Parcela.h"

class Portal{
	private:
		char estado;
		Parcela* entrada;
		Parcela* salida;
	public:

		//Post: Crea un portal de tipo "tipoDePortal" con entrada "parcelaDeEntrada" y salida "parcelaDeSalida"
		Portal(char tipoDePortal, Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida);

		//Post: Devuelve el tipo de portal
		char tipoDePortal();

		//Post: Devuelve la entrada del portal
		Parcela* entradaDelPortal();

		//Post: Devuelve la salida del portal
		Parcela* salidaDelPortal();
};



#endif /* PORTAL_H_ */
