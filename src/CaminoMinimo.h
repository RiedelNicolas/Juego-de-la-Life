#ifndef CAMINOMINIMO_H_
#define CAMINOMINIMO_H_

#include "Grafo.h"
#include "ElementoFloyd.h"

class CaminoMinimo{
private:

	unsigned int tamanio;
	ElementoFloyd** elementos;

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

private:

	/*
	 * Pre: CaminoMinimo creado
	 * Post: completa 'pesoAristas' de acuerdo a los pesos de las aristas del grafo recibido.
	 */
	void completarMatriz(Grafo*);

};




#endif /* CAMINOMINIMO_H_ */
