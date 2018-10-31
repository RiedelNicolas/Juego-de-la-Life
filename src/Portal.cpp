#include "Portal.h"

#define INACTIVO 'I'
#define ACTIVO 'A'
#define NORMAL 'N'
#define PASIVO 'P'

Portal::Portal(){
	estado = INACTIVO;
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

void Portal::atravesarPortal(Parcela* llamadoDesde){
	if(estado == ACTIVO){
		atravesarPortalActivo(llamadoDesde);
	}
	else if(estado == NORMAL && entrada == llamadoDesde){
		atravesarPortalNormal(entrada, salida);
	}
	else if(estado== PASIVO && entrada == llamadoDesde){
		hacerNacerCelula(entrada, salida);
	}
}

void Portal::atravesarPortalActivo(Parcela* llamadoDesde){
	if(entrada == llamadoDesde){
		atravesarPortalNormal(entrada, salida);
	}
	else{
		atravesarPortalNormal(salida, entrada);
	}
}

void Portal::atravesarPortalNormal(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
	hacerNacerCelula(parcelaDeEntrada, parcelaDeSalida);
	matarCelula(parcelaDeEntrada, parcelaDeSalida);
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
	return estado == ACTIVO || estado == NORMAL || estado == PASIVO || estado == INACTIVO;
}
