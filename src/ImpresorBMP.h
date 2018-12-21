#ifndef SRC_IMPRESORBMP_H_
#define SRC_IMPRESORBMP_H_

#include "EasyBMP.h"
#include "Malla.h"
#include <sstream>

#define ANCHO_CELULA 50
#define ALTO_CELULA 50

class ImpresorBMP {

public:

	ImpresorBMP();

	~ImpresorBMP();

	/*
	 * Pre: Recibe un puntero a una malla inicializada y el numero de turno en el que se encuantra el juego.
	 * Post: Imprime la malla en una imagen con el formato "nombreMalla - Turno numeroTurno .bmp".
	 */
	void imprimirMalla(Malla* malla, unsigned turno);

private:

	/*
	 *	Pre: Recibe un puntero a un BMP y un puntero a una malla validos.
	 *	Post: Carga el color por defecto de todo el BMP a blanco.
	 */
	void establecerColorMallaPorDefecto(BMP *Imagen, Malla* malla);

	/*
	 *	Pre: Recibe un puntero a un BMP y un puntero a una malla validos.
	 *	Post: Carga en el BMP la informacion de la malla.
	 */
	void cargarMallaEnImagen(BMP *Imagen, Malla* malla);

	void imprimirParcela(BMP* Imagen ,Parcela* parcela ,int i ,int j);
};



#endif /* SRC_IMPRESORBMP_H_ */
