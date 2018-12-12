#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "Arista.h"

class Grafo{

private:

	Vertice* primero;
	Vertice* cursor;
	unsigned int tamanio;

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
	 * Post: devuelve el tamanio de Grafo (Cantidad de vertices)
	 */
	unsigned int obtenerTamanio();

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
	 * Post: deja el cursor preparado para hacer un nuevo recorrido sobre sus elementos
	 */
	void iniciarCursor();

    /*
     * Pre : se ha iniciado un recorrido (invocando el método
     *       iniciarCursor()) y desde entonces no se han agregado o
     *       removido elementos de Vertice
     * Post: mueve el cursor y lo posiciona en el siguiente elemento
     *       del recorrido.
     *       El valor de retorno indica si el cursor quedó posicionado
     *       sobre un elemento o no
     */
	bool avanzarCursor();

    /*
     * Pre : el cursor está posicionado sobre un elemento de la Lista,
     *       (fue invocado el método avanzarCursor() y devolvió true)
     * Post: devuelve el elemento en la posición del cursor
     *
     */
	Vertice* obtenerCursor();

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

	/*
	 * Post: posicion debe pertenecer al intervalo [1, tamanio]
	 * Pre: devuelve Vertice en la posicion indicada
	 */
	Vertice* obtenerVertice(unsigned int posicion);
};

#endif /* GRAFO_H_ */
