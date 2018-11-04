#ifndef TABLERO_H_
#define TABLERO_H_

#include "Malla.h"
#include "Nodo.h"

class Tablero {

	private:

		Nodo* primerElemento; // Primer elemento de la lista

		unsigned tamanio; // Tamaño de la lista

		Nodo* cursor;

	public:

	/*
	 * Post: Crea una lista vacia con el primer elemento apuntando a NULL;
	 */
	Tablero();

	/*
	 * Destructor
	 * Pre: Lista creada
	 * Post: Libera los recursos utilizados por al lista.
	 */
	~Tablero();

	/*
	 * Post: Elimina todos los elementos del tablero.
	 */
	void vaciarTablero();

	/*
	 * Pre: Lista creada
	 * Post: Devuelve un bool con la respuesta a la pregunta... El tablero esta vacio??
	 */
	bool tableroVacio();

	/*
	 * Pre: Recibe una malla
	 * Post: Agrega la malla a la lista.
	 */
	void agregarMalla(Malla* nuevaMalla);

	/*
	 * Pre: Recibe un string que tiene que ser el nombre de una de las mallas
	 * Post: Devuelve un puntero a la malla con el nombre "nombreMalla"
	 */
	Malla* buscarMalla(std::string nombreMalla);

	/*
	 * Pre: Lista creada
	 * Post: Devuelve el tamaño de la lista (cantidad de nodos de la lista)
	 */

	int getTamanio();

	/*
	 * Pre: deja el cursor del Tablero preparado para hacer un nuevo
     *      recorrido sobre sus elementos.
	 */
	void iniciarCursor();

	/*
     * Pre : se ha iniciado un recorrido (invocando el método
     *       iniciarCursor()) y desde entonces no se han agregado o
     *       removido elementos del Tablero.
     * Post: mueve el cursor y lo posiciona en el siguiente elemento
     *       del recorrido.
     *       Devuelve true si el cursor quedó posicionado sobre un elemento.
     *       False en caso contrario.
     */
	bool avanzarCursor();

	/*
     * Pre : el cursor está posicionado sobre un elemento del Tablero,
     *       (fue invocado el método avanzarCursor() y devolvió true)
     * Post: devuelve el elemento en la posición del cursor.
     *
     */
	Malla* obtenerCursor();
};

#endif /* TABLERO_H_ */
