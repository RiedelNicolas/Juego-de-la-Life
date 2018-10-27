
#include "Rgb.hpp"

#define POS_ROJO 0
#define POS_VERDE 1
#define POS_AZUL 2
#define MIN_RGB 0
#define MAX_RGB 255
#define COLOR_DEFECTO 255

/*pre: recibe un int, correspondiente al valor de un color.
 * post:si el valor del color no se encuentra en el rango, tira una excepción . Siendo el rango (MIN_RGB, MAX_RGB)
 */
void verificarRango(int color);

Rgb::Rgb(int rojoIngresado, int verdeIngresado, int azulIngresado){
	verificarRango(rojoIngresado);
	verificarRango(verdeIngresado);
	verificarRango(azulIngresado);
	rojo=rojoIngresado;
	azul=azulIngresado;
	verde=verdeIngresado;
}

Rgb::Rgb(){
	rojo=COLOR_DEFECTO;
	azul=COLOR_DEFECTO;
	verde=COLOR_DEFECTO;
}

void Rgb:: setRojo(int colorIngresado){
	verificarRango(colorIngresado);
	rojo=colorIngresado;
}

void Rgb:: setVerde(int colorIngresado){
	verificarRango(colorIngresado);
	verde=colorIngresado;
}

void Rgb:: setAzul(int colorIngresado){
	verificarRango(colorIngresado);
	azul=colorIngresado;
}

int Rgb:: getRojo(){
	return rojo;
}

int Rgb:: getVerde(){
	return verde;
}

int Rgb:: getAzul(){
	return azul;
}


void verificarRango(int color){
	if( !(color<=MAX_RGB && color>=MIN_RGB) ){
		throw std::string("RGB fuera de rango");
	}
}
