#ifndef SRC_COLACONPRIORIDAD_H_
#define SRC_COLACONPRIORIDAD_H_

#include "Nodo.h"

class ColaConPrioridad {
	private:
		Nodo<int>* primero;
	public:

	ColaConPrioridad();

	void alta();

	~ColaConPrioridad();

};



#endif /* SRC_COLACONPRIORIDAD_H_ */
