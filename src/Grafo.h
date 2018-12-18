#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "Arista.h"
#include "Lista.h"

class Grafo{

private:

	Lista<Vertice*>* vertice;

public:

	/*
	 * Post: crea Grafo vacío
	 */
	Grafo();

	/*
	 * Post: devuelve un bool con la respuesta a la pregunta "¿Esta vacio?"
	 */
	bool estaVacio();

	/*
	 * Post: devuelve el vertice que tiene nombreTablero, en el caso de que no lo encuentre,
	 * 		 devuelve NULL
	 */
	Vertice* buscarVertice(std::string nombreTablero);

	/*
	 * Post: inserta un vertice al final en tamanio + 1
	 */
	void insertarVertice(std::string verticeAInsertar);

	/*
	 * Pre: verticeOrigen y verticeDestino deben existir, peso debe ser > 0
	 * Post: inserta Arista entre el verticeOrigen y verticeDestino con su peso correspondiente
	 */
	void insertarArista(std::string verticeOrigen, std::string verticeDestino, unsigned int peso);

	/*
	 * Post: aumenta en uno el peso de la arista
	 */
	void aumentarEnUnoElPeso(Arista* arista);

	/*
	 * Post: libera los recursos asociados a Grafo
	 */
	~Grafo();

private:

	/*
	 * Post: Devuelve un bool con la respuesta a la pregunta "¿existe el vértice?"
	 */
	bool existeVertice(std::string);
};

#endif /* GRAFO_H_ */
