#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Malla.h"
#include "EasyBMP.h"
#include "InterfazDeUsuario.h"

#define REINICIAR 'R'
#define TERMINAR 'T'
#define CONTINUAR 'C'
#define ANCHO_CELULA 50
#define ALTO_CELULA 50

class Juego{
	private:
		unsigned turno;
		int cantidadDeCelulasMuertas;
		int cantidadDeCelulasVivas;
		int totalCelulasMuertas;
		int totalCelulasNacidas;
		int celulasVivasTurnoAnterior;
		Tablero* tablero;
		InterfazDeUsuario* interfaz;

	public:
		/*
		 * Post: Crea un juego con "tablero" listo para ejecutarse
		 */
		Juego(Tablero* tablero);
		/*
		 * Post: Libera los recursos tomados
		 */
		~Juego();
		/*
		 * Post: Ejecuta "n" turnos. Donde "n" es un numero entero
		 * mayor a 0 ingresado por el usuario
		 */
		void nuevoTurno();

		/*
		 *Post: cambia el estado del juego a Reiniciar
		 */
		void reiniciarJuego();

		/*
		 * Post: Cambia el estado del juego a Terminar
		 */
		void finalizarJuego();

		/*
		 *Post: Inicializa el juego. Es decir, muestra un mensaje de bienvenida
		 * y le permite al usuario realizar el ingreso de las celulas deseadas
		 * en cada tablero siempre y cuando la posicion en la que se quiere
		 * ingresarla sea una valida en el tablero dado.
		 */
		void inicializarJuego();

		/*
		 * Post: imprime el resumen de un turno. Esto es:
		 * 		- La cantidad de celulas vivas
		 * 		- La cantidad de celulas que nacieron y murieron en el ultimo turno
		 * 		- El promedio de los nacimiento y muertes a lo largo del juego
		 * 		- Si el juego se ha congelado o no (es decir que los tableros no
		 * 		hayan recibido ningun cambio en dos turnos)
		 */
		void imprimirResumen();

		/*
		 * Pre: Recibe un puntero a malla inicializada
		 * Post: Imprime la malla en una imagen con el formato nombreMalla.bmp
		 */
		void imprimirMalla(Malla* malla);


		/* Pre: el tablero está creado.
		 * Post: Modifica el estado de todas las células del juego teniendo en cuenta los índices
		 * 		 de natalidad y mortalidad de cada parcela, así como los siguientes preceptos:
		 * 		 - Una célula muerta con 3 células vecinas vivas, nace.
		 * 		 - Una célula viva con 2 o 3 células vecinas vivas, permanece en ese estado.
		 * 		 - En cualquier otro caso su vida resulta reducida segun el indice de mortalidad
		 * 		 de la parcela que la contiene. De no poder reducir mas su vida(esta no puede ser
		 * 		 menor a 0) o ser esta 0 la celula muere
		 */
		void actualizarTablero();

		/* Post: Modifica el estado de todas las células de una malla teniendo en cuenta los índices
		* 		 de natalidad y mortalidad de cada parcela, así como los siguientes preceptos:
		 * 		 - Una célula muerta con 3 células vecinas vivas, nace.
		 * 		 - Una célula viva con 2 o 3 células vecinas vivas, permanece en ese estado.
		 * 		 - En cualquier otro caso su vida resulta reducida segun el indice de mortalidad
		 * 		 de la parcela que la contiene. De no poder reducir mas su vida(esta no puede ser
		 * 		 menor a 0) o ser esta 0 la celula muere
		*/
		void actualizarMalla(int filas, int columnas, Malla* malla);

		/* Pre: el tablero está creado e inicializado.
		 * Post: muestra en una imagen BMP el estado de todas las Mallas.
		 */
		void imprimirTablero();

		/*
		 * Post: Se ejecutan "cantidadDeTurnos" turnos
		 */
		void ejecutarTurnos(int cantidadDeTurnos);

		/*
		 * Post: Devuelve el promedio de "numero" por la cantidad de turnos actuales
		 */
		float calcularPromedio(int numero);

		/*
		 * Post: Devuelve un bool con la respuesta a la pregunta "¿El tablero está congelado?"
		 */
		bool tableroCongelado(int celulasNacidas, int celulasMuertas);

		/*
		 * Post: si "cantidadDeCelulas" es negativa, le asigna 0
		 */


		void validarCelulasNegativas(int &cantidadDeCelulas);

		void contarCelulasVivas();

		void ingresoDeCelulas(Malla* malla);

		void olvidoAgregarCelulasEnTablero();

		char obtenerOrdenPorPantalla();

};



#endif /* SRC_JUEGO_H_ */
