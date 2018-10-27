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

void Portal::activarPortal(Parcela* llamadoDesde){
	if(estado == 'A'){
		if(llamadoDesde->getEstadoDeCelula()){
			salida->setEstadoDeCelula(true);
		}
		else{
			salida->setEstadoDeCelula(false);
		}
	}
	else if(estado == 'N' && entrada == llamadoDesde){
		if(llamadoDesde->getEstadoDeCelula()){
			salida->setEstadoDeCelula(true);
		}
		else{
			salida->setEstadoDeCelula(false);
		}
	}
	else if(estado=='P' && entrada == llamadoDesde){
		if(llamadoDesde->getEstadoDeCelula()){
			salida->setEstadoDeCelula(true);
		}
	}
}
