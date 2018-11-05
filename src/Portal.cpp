#include "Portal.h"
#include <iostream>

#define INACTIVO 'I'
#define ACTIVO 'A'
#define NORMAL 'N'
#define PASIVO 'P'
#define NACE 'N'
#define MUERE 'M'

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
		atravesarPortalActivo(llamadoDesde, estadoEnQueAtraviesa);
	}
	else if(estado == NORMAL && entrada == llamadoDesde){
		atravesarPortalNormal(entrada, salida, estadoEnQueAtraviesa);
	}
	else if(estado== PASIVO && entrada == llamadoDesde){
		hacerNacerCelula(entrada, salida);
	}
}

void Portal::atravesarPortalActivo(Parcela* llamadoDesde, char estadoEnQueAtraviesa){
	if(entrada == llamadoDesde){
		atravesarPortalNormal(entrada, salida, estadoEnQueAtraviesa);
	}
	else{
		atravesarPortalNormal(salida, entrada, estadoEnQueAtraviesa);
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
}

void Portal::matarCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida){
		parcelaDeSalida->reducirVidaDeCelula();
}

bool Portal::estadoEsValido(char estado){
	return estado == ACTIVO || estado == NORMAL || estado == PASIVO || estado == INACTIVO;
}
