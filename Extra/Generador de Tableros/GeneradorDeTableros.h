#ifndef GENERADOR_DE_TABLEROS_H_
#define GENERADOR_DE_TABLEROS_H_

#include <fstream>
#include <string>

class GeneradorDeTableros{
private:
	std::string ruta;
	std::ofstream salida;

public:
	/*
	 * 	Post: genera un archivo de salida en la ruta indicada.
	 */
	GeneradorDeTableros(std::string ruta);

	/*
	 * Pre: ya existe el archivo de salida.
	 * Post: carga los tableros ingresados por el usuario en el archivo.
	 */
	void pedirTableros();

	/*
	 * Pre: ya están cargados los tableros.
	 * Post: carga las parcelas en el archivo.
	 */
	void generarParcelas();

	/*
	 * Pre: ya están cargados los tableros y las parcelas.
	 * Post: carga los portales ingresados por el usuario en el archivo.
	 */
	void pedirPortales();

private:

	/*
	 * Post: devuelve un bool de acuerdo a la respuesta del usuario
	 * 		 al 'mensaje'.
	 * 		 true si respondo SI, false si respondió NO;
	 */
	bool preguntarAlUsuario(std::string mensaje);

};

#endif /* BIBLIOTECA_H_ */
