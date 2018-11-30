
#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_

#include "Arista.h"

class Arista;

class Vertice{

private:

	Vertice* siguiente;
	Arista* adyacente;
	Arista* cursor;
	std::string nombreVertice;
	unsigned int tamanio;

public:

	Vertice(std::string nombreTablero);

	Vertice* obtenerSiguiente();

	void cambiarSiguiente(Vertice* nuevoSiguiente);

	std::string obtenerNombreVertice();

	void insertarArista(unsigned int peso, Vertice* destino);

	Arista* buscarAristaAdyacente(Vertice* vertice);

	void iniciarCursor();

	bool avanzarCursor();

	Arista* obtenerCursor();

	~Vertice();

private:

	bool verticeEsAdyacente(Vertice*);

	Arista* obtenerArista(unsigned int posicion);


};




#endif /* SRC_VERTICE_H_ */
