#ifndef GRAFO_H_
#define GRAFO_H_

class Grafo{

	public:
		int cantidadDeVertices;
		int* adyacencias;
	private:
		/*
		 * Post: genera el grafo vacío.
		 */
		Grafo(int dimension);

};



#endif /* GRAFO_H_ */
