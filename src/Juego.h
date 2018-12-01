#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Grafo.h
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
		int cantidadDeCelulasNacidas;
		int cantidadDeCelulasVivas;
		int totalCelulasMuertas;
		int totalCelulasNacidas;
		Tablero* tablero;
		Grafo* grafo;
		InterfazDeUsuario* interfaz;

	public:
		/*
		 * Post: Crea un juego con "tablero" listo para ejecutarse
		 */
		Juego(Tablero* tablero, Grafo* grafo);
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

		/* Pre: el tablero está creado e inicializado.
		 * Post: muestra en una imagen BMP el estado de todas las Mallas.
		 */
		void imprimirTablero();

		/*
		 * Pregunta ,por consola, como se desea continuar con el juego.
		 * Devuelve la respuesta seleccionada por el usuario en forma de char.
		 */
		char obtenerOrdenPorPantalla();

	private:

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
		void actualizarMalla(Malla* malla);

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

		/*pre: Tablero correctamente cargado
		 * post:actualiza el valor del atributo "cantidadDeCelulasVivas"
		 */
		void contarCelulasVivas();

		/*
		 * pre: se le pasa por parametro una malla valida.
		 * Post: le permite a el usuario ingresar celulas vivas a eleccion.
		 */
		void ingresoDeCelulas(Malla* malla);

		/*
		 * pre: Tablero correctamente formado.
		 * post: da la opcion a el usuario de cargar celulas en un tablero a eleccion.
		 */
		void olvidoAgregarCelulasEnTablero();

		/*
		 * Pre: Recibe un puntero a parcela valido
		 * Post: Calcula cuanto debe variar la vida de la celula correspondiente a la parcela
		 * en dicho turno y aplica los cambios correspondientes. Devuelve un equivalente a dicha celula.
		 */

		Celula calcularRestaVidaCelula(Parcela* parcela);

		/*
		 * Pre: Recibe un puntero a malla valido
		 * Post: Devuelve un puntero a un array bidimensional de "Celulas" de las dimensiones de la malla
		 */
		Celula** crearAuxiliar(Malla* malla);

		/*
		 * Pre: Recibe un puntero a malla valido y un puntero a un array bidimensional de "Celulas"
		 * Post: Libera la memoria ocupada por "auxiliar"
		 */
		void destruirAuxiliar(Celula** auxiliar , Malla* malla);

		/*
		 * Pre: Recibe un puntero a un array bidimensional de "Celula" valido y un puntero a malla valido.
		 * Post: Reemplaza las celulas de "malla" por las de "auxiliar"
		 */
		void reemplazarAuxiliar(Celula** auxiliar, Malla* malla);

		/*
		 *	Pre: Recibe un puntero a un BMP y un puntero a una malla validos.
		 *	Post: Carga el color por defecto de todo el BMP a blanco.
		 */
		void establecerColorMallaPorDefecto(BMP *Imagen, Malla* malla);

		/*
		 *	Pre: Recibe un puntero a un BMP y un puntero a una malla validos.
		 *	Post: Carga en el BMP la informacion de la malla.
		 */
		void cargarMallaEnImagen(BMP *Imagen, Malla* malla);

		/*
		 *  Pre: Recibe un puntero a Celula y un puntero a Parcela Validos
		 *  Post: Carga en la "celula" la vida con la que quedaria la celula de la "parcela" al pasar de turno,
		 *  	  Es importante aclarar que esta funcion se invoca solo si la celula sufre daño por estar rodeada
		 *  	  de menos de 2 celulas vivas o mas de 3 celulas vivas
		 */
		void reducirVidaCelula(Celula* celula, Parcela* parcela);

		/*
		 * pre: Recibe una celula, una parcela y un RGB por parametros.
		 * post: Da la vida y el color correspondiente a la celula por nacer,
		 * realiza las interacciones correspondientes con el portal.
		 */

		void hacerNacerCelula(Celula* celulaAux, Parcela* parcela, Rgb* nuevoColorCelula);

};

#endif /* SRC_JUEGO_H_ */
