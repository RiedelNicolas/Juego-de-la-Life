
#ifndef GRAFO2_H_
#define GRAFO2_H_

#include "Vertice.h"
#include "Arista.h"

class Grafo{

private:

	Vertice* primero;
	Vertice* cursor;
	unsigned int tamanio;

public:

	Grafo();

	bool estaVacio();

	unsigned int obtenerTamanio();

	Vertice* buscarVertice(std::string nombreTablero);

	void insertarArista(std::string origen, std::string destino, unsigned int peso);

	void insertarVertice(std::string verticeAInsertar);

	void iniciarCursor();

	bool avanzarCursor();

	Vertice* obtenerCursor();

	~Grafo();

private:

	bool existeVertice(std::string);

	Vertice* obtenerVertice(unsigned int posicion);

};



#endif /* GRAFO2_H_ */




