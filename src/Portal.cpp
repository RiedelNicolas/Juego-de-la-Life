#include "Portal.h"

Portal::Portal(){
	estado = 'I';
	entrada = NULL;
	salida = NULL;
}

void Portal::setEstado(char nuevoEstado){
	estado = nuevoEstado;
}

void Portal::setEntrada(Parcela* parcelaDeEntrada){
	entrada = parcelaDeEntrada;
}

void Portal::setSalida(Parcela* parcelaDeSalida){
	entrada = parcelaDeSalida;
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
