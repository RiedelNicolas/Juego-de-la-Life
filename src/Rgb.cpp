
#include "Rgb.h"

#define POS_ROJO 0
#define POS_VERDE 1
#define POS_AZUL 2
#define MIN_RGB 0
#define MAX_RGB 255

/*pre: recibe un int, correspondiente al valor de un color.
 * post:si el valor del color no se encuentra en el rango, tira una excepción . Siendo el rango (MIN_RGB, MAX_RGB)
 */
void verificarRango(int color);

Color::Color(int rojo =0 ,int verde = 0,int azul=0){
	verificarRango(rojo);
	verificarRango(verde);
	verificarRango(azul);
	this->colores[POS_ROJO] = rojo;
	this->colores[POS_VERDE] =verde;
	this->colores[POS_AZUL] =azul;
}

void Color::setColor(int colorIngresado, std::string color){
	verificarRango(colorIngresado);
	int pos;
	switch(color){
		case "ROJO":
			pos= POS_ROJO;
			break;
		case "VERDE":
			pos= POS_VERDE;
			break;
		case "AZUL":
			pos= POS_AZUL;
			break;
	colores[pos]=colorIngresado;
	}

}

void Color:: setRojo(int colorIngresado){
	verificarRango(colorIngresado);
	colores[POS_ROJO]=colorIngresado;
}

void Color::setVerde(int colorIngresado){
	verificarRango(colorIngresado);
	colores[POS_VERDE]=colorIngresado;
}

void Color::setAzul(int colorIngresado){
	verificarRango(colorIngresado);
	colores[POS_AZUL]=colorIngresado;
}

int Color::getRojo(){
	return colores[POS_ROJO];
}

int Color::getVerde(){
	return colores[POS_VERDE];
}

int Color::getAzul(){
	return colores[POS_AZUL];
}


void verificarRango(int color){
	if( !(color<=MAX_RGB && color>=MIN_RGB) ){
		throw;
	}
}



