#ifndef PORTAL_H_
#define PORTAL_H_

#include <iostream>
#include "Parcela.h"
#include <string>
class Parcela;

class Portal{
	private:
		char estado;
		Parcela* entrada;
		Parcela* salida;

	public:
		/*
		*Post: Crea un portal de tipo "tipoDePortal" con entrada "parcelaDeEntrada" y salida "parcelaDeSalida"
		*/
		Portal();
		/*
		 * Pre: El estado debe ser un estado valido. A saber:
		 *  'P' = pasivo; 'N' = normal; 'A' = Activo; 'I'=Inactivo
		 * Post: Actualiza el estado del Portal por "nuevoEstado"
		 */
		void setEstado(char nuevoEstado);
		/*
		 * Post: Se actualiza la entrada del portal por "parcelaDeEntrada"
		 */
		void setEntrada(Parcela* parcelaDeEntrada);
		/*
		 * Post: Se actualiza la salida del portal por "parcelaDeSalida"
		 */
		void setSalida(Parcela* parcelaDeSalida);
		/*
		 * Post: Devuelve el tipo de portal
		 */
		char getTipo();
		/*
		*Post: Devuelve un puntero a la parcela de entrada del portal
		*/
		Parcela* getEntrada();
		/*
		*Post: Devuelve un puntero a la parcela de salida del portal
		*/
		Parcela* getSalida();
		/*
		 * Post:
		 * WARNING HABRIA QUE VER LO DE QUE COPIE LOS COLORES DE LAS CELULAS CIRCUNDANTES
		 */
		void atravesarPortal(Parcela* llamadoDesde);

	private:
		/*
		 * Post: Devuelve si el estado ingresado es un estado valido o no
		 */
		bool estadoEsValido(char estado);
		/*
		 * Post: Si la celula de la parcela de entrada nacio, nacera una celula en la parcela salida del portal
		 * Si la celula de la entrada murio, morira la celula de la salida del portal
		 * Los cambios de la celula de la salida del portal no afectan a la celula de la
		 * parcela de entrada
		 */
		void atravesarPortalNormal();
		/*
		 *
		 */
		void hacerNacerCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida);
		/*
		 *
		 */
		void matarCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida);


};


#endif /* PORTAL_H_ */
