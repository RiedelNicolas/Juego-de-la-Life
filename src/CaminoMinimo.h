#ifndef CAMINOMINIMO_H_
#define CAMINOMINIMO_H_

#include "Grafo.h"
#include "ElementoFloyd.h"

class CaminoMinimo{
private:

	unsigned int tamanio;
	ElementoFloyd** elementos;
	Grafo* grafo;

public:

	/*
	 * Post: recibe un grafo y deja a 'CaminoMinimo' lista para usarse.
	 */
	CaminoMinimo(Grafo*);

	/*
	 * Pre: CaminoMinimo creado.
	 * Post: libera los recursos pedidos.
	 */
	~CaminoMinimo();

	unsigned int calcularTransferenciaMinima(std::string origen, std::string destino);

private:

	/*
	 * Pre: CaminoMinimo creado.
	 * Post: completa el arreglo de elementos de acuerdo a los pesos de las aristas del grafo.
	 */
	void completarMatriz();

	/*
	 * Pre: CaminoMinimo creado.
	 * Post: devuelve el elemento correspondiente al origen y destino recibidos.
	 */
	ElementoFloyd buscarElemento(std::string origen, std::string destino);

};




#endif /* CAMINOMINIMO_H_ */
