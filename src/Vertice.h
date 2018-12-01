
#ifndef SRC_VERTICE_H_
#define SRC_VERTICE_H_

#include "Arista.h"
#include <iostream>

class Arista;

class Vertice{

private:

	Vertice* siguiente;
	Arista* adyacente;
	Arista* cursor;
	std::string nombreVertice;
	unsigned int tamanio;

public:
	/*
	 * Post: crea Vertice indicando su nombre
	 */
	Vertice(std::string nombreTablero);

	/*
	 * Post: devuelve el siguiente Vertice
	 */
	Vertice* obtenerSiguiente();

	/*
	 * Post: cambia siguiente Vertice por nuevoSiguiente
	 */
	void cambiarSiguiente(Vertice* nuevoSiguiente);

	/*
	 * Post: devuelve el nombre asignado a Vertice
	 */
	std::string obtenerNombreVertice();

	/*
	 * Post: inserta la arista al final de la Lista en tamanio + 1
	 */
	void insertarArista(unsigned int peso, Vertice* destino);

	/*
	 * Post: devuelve la arista adyacente al vertice que se le pasa por parámetro
	 */
	Arista* buscarAristaAdyacente(Vertice* vertice);

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
	Arista* obtenerCursor();

	/*
	 * Post: devuelve un bool con la respuesta a la pregunta "¿el vértice es adyacente?"
	 */
	bool esVerticeAdyacente(Vertice* verticeABuscar);

    /*
     * Post: libera los recursos asociados a Vertice
     */
	~Vertice();

private:

	/*
	 * Post: posicion debe pertenecer al intervalo [1, tamanio]
	 * Pre: devuelve Arista en la posicion indicada
	 */
	Arista* obtenerArista(unsigned int posicion);


};


#endif /* SRC_VERTICE_H_ */
