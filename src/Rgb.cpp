
#include "Rgb.hpp"


#define MIN_RGB 0
#define MAX_RGB 255

/*pre: recibe un int, correspondiente al valor de un color.
 * post:si el valor del color no se encuentra en el rango, tira una excepción . Siendo el rango (MIN_RGB, MAX_RGB)
 */

void verificarRango(int color);

Rgb::Rgb(int rojoIngresado, int verdeIngresado, int azulIngresado){
	verificarRango(rojoIngresado);
	verificarRango(verdeIngresado);
	verificarRango(azulIngresado);
	this->rojo = rojoIngresado;
	this->azul = azulIngresado;
	this->verde = verdeIngresado;
}

Rgb::Rgb(){
	this->rojo=COLOR_POR_DEFECTO;
	this->azul=COLOR_POR_DEFECTO;
	this->verde=COLOR_POR_DEFECTO;
}

void Rgb:: setRojo(int colorIngresado){
	verificarRango(colorIngresado);
	this->rojo=colorIngresado;
}

void Rgb:: setVerde(int colorIngresado){
	verificarRango(colorIngresado);
	this->verde=colorIngresado;
}

void Rgb:: setAzul(int colorIngresado){
	verificarRango(colorIngresado);
	this->azul=colorIngresado;
}

int Rgb:: getRojo(){
	return (this->rojo);
}

int Rgb:: getVerde(){
	return (this->verde);
}

int Rgb:: getAzul(){
	return (this->azul);
}

void verificarRango(int color){
	if( !(color<=MAX_RGB && color>=MIN_RGB) ){
		throw std::string("RGB fuera de rango");
	}
}
