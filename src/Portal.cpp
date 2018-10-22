#include <iostream>
#include "Portal.h"

Portal::Portal(char tipoDePortal, Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
	estado = tipoDePortal;
	entrada = parcelaDeEntrada;
	salida = parcelaDeSalida;
}

char Portal::tipoDePortal(){
	return estado;
}

Parcela* Portal::entradaDelPortal(){
	return entrada;
}

Parcela* Portal::salidaDelPortal(){
	return salida;
}
