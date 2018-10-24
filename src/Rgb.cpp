
#include "Rgb.hpp"

#define POS_ROJO 0
#define POS_VERDE 1
#define POS_AZUL 2
#define MIN_RGB 0
#define MAX_RGB 255

/*pre: recibe un int, correspondiente al valor de un color.
 * post:si el valor del color no se encuentra en el rango, tira una excepción . Siendo el rango (MIN_RGB, MAX_RGB)
 */
void verificarRango(int color);

Rgb::Rgb(int rojo =0 ,int verde = 0,int azul=0){
	verificarRango(rojo);
	verificarRango(verde);
	verificarRango(azul);
	this->colores[POS_ROJO] = rojo;
	this->colores[POS_VERDE] =verde;
	this->colores[POS_AZUL] =azul;
}

void Rgb:: setRojo(int colorIngresado){
	verificarRango(colorIngresado);
	colores[POS_ROJO]=colorIngresado;
}

void Rgb:: setVerde(int colorIngresado){
	verificarRango(colorIngresado);
	colores[POS_VERDE]=colorIngresado;
}

void Rgb:: setAzul(int colorIngresado){
	verificarRango(colorIngresado);
	colores[POS_AZUL]=colorIngresado;
}

int Rgb:: getRojo(){
	return colores[POS_ROJO];
}

int Rgb:: getVerde(){
	return colores[POS_VERDE];
}

int Rgb:: getAzul(){
	return colores[POS_AZUL];
}


void verificarRango(int color){
	if( !(color<=MAX_RGB && color>=MIN_RGB) ){
		throw;
	}
}



