#include <iostream>
#include "Portal.h"

Portal::Portal(char tipoDePortal, Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
	estado = tipoDePortal;
	entrada = parcelaDeEntrada;
	salida = parcelaDeSalida;
}

char Portal::getTipo(){
	return estado;
}

Parcela* Portal::getEntrada(){
	return entrada;
}

Parcela* Portal::getSalida(){
	return salida;
}

