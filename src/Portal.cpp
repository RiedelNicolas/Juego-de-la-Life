#include "Portal.h"
#include <iostream>


Portal::Portal(){
	estado = INACTIVO;
	entrada = NULL;
	salida = NULL;
	mallaDeEntrada = "";
	mallaDeSalida = "";
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

void Portal::setMallaDeEntrada(std::string nombre){
	mallaDeEntrada = nombre;
}

void Portal::setMallaDeSalida(std::string nombre){
	mallaDeSalida = nombre;
}

std::string Portal::getMallaDeEntrada(){
	return mallaDeEntrada;
}

std::string Portal::getMallaDeSalida(){
	return mallaDeSalida;
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

void Portal::atravesarPortal(Parcela* llamadoDesde, char estadoEnQueAtraviesa){
	if(estado == ACTIVO){
		atravesarPortalNormal(entrada, salida, estadoEnQueAtraviesa);
	}
	else if(estado == NORMAL && entrada == llamadoDesde){
		atravesarPortalNormal(entrada, salida, estadoEnQueAtraviesa);
	}
	else if(estado== PASIVO && entrada == llamadoDesde && estadoEnQueAtraviesa==NACE){
		hacerNacerCelula(entrada, salida);
	}
}

void Portal::atravesarPortalNormal(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida, char estadoEnQueAtraviesa){
	if(estadoEnQueAtraviesa == NACE){
		hacerNacerCelula(parcelaDeEntrada, parcelaDeSalida);
	}
	else{
		matarCelula(parcelaDeEntrada, parcelaDeSalida);
	}
}

void Portal::hacerNacerCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
		parcelaDeSalida->setEstadoDeCelula(true);
		parcelaDeSalida->getCelula()->setRgb(parcelaDeSalida->getRgb());
		parcelaDeSalida->getCelula()->nacioMediantePortal(true);
}

void Portal::matarCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
		parcelaDeSalida->reducirVidaDeCelula();
}

bool Portal::estadoEsValido(char estado){
	return estado == ACTIVO || estado == NORMAL || estado == PASIVO || estado == INACTIVO;
}
