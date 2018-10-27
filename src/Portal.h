#ifndef PORTAL_H_
#define PORTAL_H_


#include <iostream>
#include "Parcela.h"
class Parcela;

class Portal{
	private:
		char estado;
		Parcela* entrada;
		Parcela* salida;

	public:
// P = pasivo; N = normal; A = Activo; I=Inactivo

		//Post: Crea un portal de tipo "tipoDePortal" con entrada "parcelaDeEntrada" y salida "parcelaDeSalida"
		Portal();

		void setEstado(char nuevoEstado);

		void setEntrada(Parcela* parcelaDeEntrada);

		void setSalida(Parcela* parcelaDeSalida);

		//Post: Devuelve el tipo de portal
		char getTipo();

		//Post: Devuelve un puntero a la parcela de entrada del portal
		Parcela* getEntrada();

		//Post: Devuelve un puntero a la parcela de salida del portal
		Parcela* getSalida();

		void activarPortal(Parcela* llamadoDesde);

};



#endif /* PORTAL_H_ */
