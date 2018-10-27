
#ifndef RGB_HPP_
#define RGB_HPP_

//redefinir operador
#include <iostream>

class Rgb{
private:
	int rojo;
	int verde;
	int azul;
public:
	/*constructor,
	 * pre : recibe los 3 enteros correspondiente a los valores del Rgb. Rango(0-255), inicializa en 0 si no se reciben parametros.
	 * post:asigna los valores recibidos a el RGB, luego de crear el mismo.
	 */
	Rgb(int rojo ,int verde ,int azul);

	/*pre: recibe un valor entero en el rango (0-255)
	 * post: asigna dicho valor a el color correspondiente del Rgb.
	 */
	void setRojo(int);
	void setVerde(int);
	void setAzul(int);

	/*post: Devuelve un entero correspondiente al valor de dicho color en el RGB.
	 */
	int getRojo();
	int getVerde();
	int getAzul();

	//redefinir el operador


};


#endif /* RGB_HPP_ */
