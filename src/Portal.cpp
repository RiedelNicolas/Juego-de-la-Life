#include "Portal.h"

Portal::Portal(){
	estado = 'I';
	entrada = NULL;
	salida = NULL;
}

void Portal::setEstado(char nuevoEstado){
	if(estadoEsValido(nuevoEstado)){
		estado = nuevoEstado;
	}
	else{
		throw std::string("Estado No Valido");
	}
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

void Portal::atravesarPortal(Parcela* llamadoDesde){
	if(estado == 'A'){
		if(entrada == llamadoDesde){
			atravesarPortalNormal();
		}
		else{
			hacerNacerCelula(salida, entrada);
			matarCelula(salida, entrada);
		}
	}
	else if(estado == 'N' && entrada == llamadoDesde){
		atravesarPortalNormal();
	}
	else if(estado== 'P' && entrada == llamadoDesde){
		hacerNacerCelula(entrada, salida);
	}
}

void Portal::atravesarPortalNormal(){
	hacerNacerCelula(entrada, salida);
	matarCelula(entrada, salida);
}

void Portal::hacerNacerCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
	if(parcelaDeEntrada->getEstadoDeCelula()){
		parcelaDeSalida->setEstadoDeCelula(true);
	}
}

void Portal::matarCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
	if(!parcelaDeEntrada->getEstadoDeCelula()){
		parcelaDeSalida->setEstadoDeCelula(false);
	}
}

bool Portal::estadoEsValido(char estado){
	return estado == 'A' || estado == 'N' || estado == 'P' || estado == 'I';
}





