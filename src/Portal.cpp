#include "Portal.h"
#include <iostream>


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

void Portal::atravesarPortal(Parcela* llamadoDesde, char estadoEnQueAtraviesa){
	if(estado == ACTIVO){
		atravesarPortalNormal(entrada, salida, estadoEnQueAtraviesa);
		std::cout << "entro1";
	}
	else if(estado == NORMAL && entrada == llamadoDesde){
		atravesarPortalNormal(entrada, salida, estadoEnQueAtraviesa);
		std::cout << "entro2";
	}
	else if(estado== PASIVO && entrada == llamadoDesde && estadoEnQueAtraviesa==NACE){
		hacerNacerCelula(entrada, salida);
		std::cout << "entro3";
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
