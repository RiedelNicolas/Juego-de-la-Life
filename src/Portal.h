#ifndef PORTAL_H_
#define PORTAL_H_

#include <iostream>
#include "Parcela.h"
#include <string>

#define INACTIVO 'I'
#define ACTIVO 'A'
#define NORMAL 'N'
#define PASIVO 'P'
#define NACE 'N'
#define MUERE 'M'

class Parcela;

class Portal{

	private:

		char estado;
		Parcela* entrada;
		Parcela* salida;
		std::string mallaDeEntrada;
		std::string mallaDeSalida;

	public:

		/*
		*Post: Crea un portal de tipo Inactivo ('I') y con tanto entrada y salida
		*nulas
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

		void setMallaDeEntrada(std::string nombre);

		void setMallaDeSalida(std::string nombre);

		std::string getMallaDeSalida();

		std::string getMallaDeEntrada();
		/*
		 * Post: Devuelve el tipo de portal
		 */
		char getTipo();

		/*
		 * Post: Devuelve un puntero a la parcela de entrada del portal
		 */
		Parcela* getEntrada();

		/*
		 * Post: Devuelve un puntero a la parcela de salida del portal
		 */
		Parcela* getSalida();

		/*
		 * Pre: Recibe una parcela valida con un portal, y el estado en que la celula atraviesa el portal.
		 * Post: Efectua la accion de que una celula atraviese el portal .Ejemplo: si la celula nace, nace del otro lado
		 * del portal, y si muere, muere del otro lado del portal.
		 */
		void atravesarPortal(Parcela* llamadoDesde, char estadoEnQueAtraviesa);

	private:

		/*
		 * Post: Devuelve si el estado ingresado es un estado valido o no
		 */
		bool estadoEsValido(char estado);

		/*
		 * Post: Si la celula de "parcelaDeEntrada" nacio, nacera una celula en "parcelaDeSalida" del portal
		 * Si la celula de "parcelaDeEntrada"  murio, morira la celula de "parcelaDeSalida" del portal
		 * Los cambios de la celula en "parcelaDeSalida" no afectan a la celula de "parcelaDeEntrada"
		 */
		void atravesarPortalNormal(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida, char estadoEnQueAtraviesa);

		/*
		 * Post: Si la celula en "parcelaDeEntrada" esta viva
		 * entonces nace la celula de "parcelaDeSalida". De Estar muerta la celula en
		 * "parcelaDeEntrada" no hace nada.
		 */
		void hacerNacerCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida);

		/*
		 * Post: Si la celula en "parcelaDeEntrada" esta muerta
		 * entonces mata a  la celula de "parcelaDeSalida". De Estar viva la celula en
		 * "parcelaDeEntrada" no hace nada.
		 */
		void matarCelula(Parcela* parcelaDeEntrada, Parcela* parcelaDeSalida);
};

#endif /* PORTAL_H_ */
