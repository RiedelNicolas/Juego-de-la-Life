#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <iostream>
#include "Malla.h"

template <class T> class Nodo {

	private:

		T elemento;
		Nodo<T>* siguiente;

	public:

		/*
		 * Pre: Recibe un puntero a Malla
		 * Post: Asigna ese puntero al puntero a malla del Nodo
		 */
		Nodo(T elemento);

		/*
		 * Post: Libera los recursos utilizados por el Nodo
		 */
		~Nodo();

		/*
		 * Post: Devuelve un puntero a la malla correspondiente al nodo
		 */
		T getElemento();

		/*
		 * Post: Devuelve un puntero al siguiente Nodo, en caso
		 * de que no exista un siguiente Nodo, ese puntero va a ser NULL */
		Nodo<T>* getSiguiente();

		/*
		 * Pre: Recibe un puntero a un Nodo
		 * Post: Asigna ese puntero a Nodo como siguiente Nodo
		 */
		void setSiguiente(Nodo<T>* nuevoSiguiente);
};

template<class T> Nodo<T>::Nodo(T elementoRecibido){
	this->elemento = elementoRecibido;
	this->siguiente = NULL;
}

template<class T> Nodo<T>::~Nodo(){
	delete (this->elemento); //ESTO ESTÁ CHEQUEADO??
}

template<class T> T Nodo<T>::getElemento(){
	return (this->elemento);
}

template<class T> Nodo<T>* Nodo<T>::getSiguiente(){
	return (this->siguiente);
}

template <class T> void Nodo<T>::setSiguiente(Nodo<T>* nuevoSiguiente){
	this->siguiente = nuevoSiguiente;
}

#endif /* SRC_NODO_H_ */
