#include "Malla.h"

using namespace std;

Malla::Malla(int filas, int columnas, string nombre){

	this->nombre = nombre;
	ancho = columnas;
	alto = filas;
	celulasVivas = 0;
	parcelas = new Parcela*[alto];

	for(int i = 0; i < alto; i++){
		parcelas[i] = new Parcela[ancho];
	}
}


Malla::~Malla(){

	for(int i = 0; i < alto; i++){
		delete[] parcelas[i];
	}
	delete[] parcelas;
}

int Malla::getCantidadDeFilas(){
	return alto;
}

int Malla::getCantidadDeColumnas(){
	return ancho;
}

std::string Malla::getNombre(){
	return nombre;
}

Parcela* Malla::getParcela(int fila,int columna){ //ESTO NO ESTA CHEQUEADO. WARNING!! EXPERIMENTAL.
	return &(parcelas[fila][columna]);
}

int Malla::getCantidadDeCelulasVivas(){

	celulasVivas = 0;

	for(int i=0; i<alto; i++){
		for(int j=0; j<ancho; j++){

			if(parcelas[i][j].getEstadoDeCelula()){
				celulasVivas++;
			}
		}
	}
	return celulasVivas;
}

int Malla::contarCelulasVivasLindantes(int fila, int columna){
	int contadorCelulasVivas = 0;

	for(int i=-1; i<2; i++){
		for(int j=-1; j<2; j++){
			if( !(j==0 && i==0) && posicionValida(fila+i,columna+j)
				&& parcelas[fila+i][columna+j].getEstadoDeCelula()){
					contadorCelulasVivas++;
			}
		}
	}
	//cout << fila << ", " << columna << ": "<< contadorCelulasVivas << endl;
	return contadorCelulasVivas;
}

bool Malla::posicionValida(int fila, int columna){
	return ((fila >= 0) && (fila < alto) && (columna >= 0) && (columna < ancho));
}


Rgb Malla::obtenerColorPromedioDeVecinasVivas(int fila, int columna){
	Rgb colorPromedio(0,0,0);
	int vecinasVivas = 0;
	int rojoTotal = 0 , azulTotal = 0, verdeTotal = 0;
	Rgb rgbAuxiliar;

	for(int i=-1; i<2; i++){
		for(int j=-1; j<2; j++){
			if(posicionValida(fila+i,columna+j) && parcelas[fila+i][columna+j].getEstadoDeCelula()){
				if( parcelas[fila+i][columna+j].getEstadoDeCelula() && !(i==0 && j ==0 ) ){ //si la parcela esta viva y no es la que estoy parado.
					rgbAuxiliar  = parcelas[fila+i][columna+j].getCelula()->getRgb();
					rojoTotal += rgbAuxiliar.getRojo();
					azulTotal += rgbAuxiliar.getAzul();
					verdeTotal += rgbAuxiliar.getVerde();
					vecinasVivas ++;
				}
			}
		}
	}


	if( vecinasVivas==0 ){ //si no hay celulas vivas, devuelvo el color que tiene la parcela.
		colorPromedio = parcelas[fila][columna].getCelula()->getRgb() ;
	}else{
		colorPromedio.setRojo(rojoTotal/vecinasVivas);
		colorPromedio.setVerde( verdeTotal/vecinasVivas);
		colorPromedio.setAzul(azulTotal/vecinasVivas);
	}

	return colorPromedio;
}
