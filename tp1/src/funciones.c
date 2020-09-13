#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

/** \brief: funcion que solicita numero y lo valida
 *
 * \param char* msg: mensaje que solicita ingreso de numero
 * \param char* msgError: mensaje que informa que el valor ingresado es incorrecto
 * \param float *pResultado: puntero en donde se guarda el numero ingresado
 * \param int reintentos: cantidad de intentos validos para ingresar un numero
 * \return (-1) si no se pudo obtener numero, (0) si el numero se obtuvo de manera exitosa
 */
int getFloat(char *msg, char *msgError, float *pResultado, int reintentos) {
	int output = -1;
	char bufferFloat[20];
	if (msg != NULL && msgError != NULL && pResultado != NULL
			&& reintentos > 0) {
		do {
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%s", bufferFloat);
			for (int x = 0; bufferFloat[x] != '\0'; x++) {
				if ((bufferFloat[x] >= '0' && bufferFloat[x] <= '9')
						|| bufferFloat[x] == '.') {
					output = 0;
				} else {
					reintentos--;
					output = -1;
					if (reintentos > 0) {
						printf("%s: %d", msgError, reintentos);
					}
					break;
				}
			}
		} while (output != 0 && reintentos > 0);
	} //fin if
	if (output == 0) {
		*pResultado = atof(bufferFloat);
	}
	return output;
}

/** \brief: funcion que suma dos numeros
 *
 * \param float *pResultado: puntero en donde se guarda el resultado de la suma
 * \param float a: el primer numero
 * \param float b: el segundo numero
 * \return (-1) si no se pudo realizar suma, (0) si se realizo suma de manera exitosa
 */
int getSum(float *pResultado, float a, float b) {
	int output = -1;
	if (pResultado != NULL) {
		*pResultado = a + b;
		output = 0;
	}
	return output;
}

/** \brief: funcion que resta dos numeros
 *
 * \param float *pResultado: puntero en donde se guarda el resultado de la resta
 * \param float a: el primer numero
 * \param float b: el segundo numero
 * \return (-1) si no se pudo realizar resta, (0) si se realizo resta de manera exitosa
 */
int getSubtraction(float *pResultado, float a, float b) {
	int output = -1;
	if (pResultado != NULL) {
		*pResultado = a - b;
		output = 0;
	}
	return output;
}

/** \brief: funcion que multiplica dos numeros
 *
 * \param float *pResultado: puntero en donde se guarda el resultado del producto
 * \param float a: el primer numero
 * \param float b: el segundo numero
 * \return (-1) si no se pudo realizar el producto, (0) si se realizo el producto de manera exitosa
 */
int getProduct(float *pResultado, float a, float b) {
	int output = -1;
	if (pResultado != NULL) {
		*pResultado = a * b;
		output = 0;
	}
	return output;
}

/** \brief: funcion que divide dos numeros
 *
 * \param float *pResultado: puntero en donde se guarda el resultado de la division
 * \param float a: el primer numero
 * \param float b: el segundo numero
 * \return (-1) si no se pudo realizar la division, (0) si se realizo la division de manera exitosa
 */
int getDivision(float *pResultado, float a, float b) {
	int output = -1;
	if (pResultado != NULL && b != 0) {
		*pResultado = a / b;
		output = 0;
	}
	return output;
}

/** \brief: funcion que valida si el usuario ingreso un numero entero
 *
 * \param float numero: el numero a validar
 * \return (-1) si no se pudo realizar la validacion, (0) si se realizo la validacion de manera exitosa
 */

int isFloat(float numero) {
	int bufferInt;
	int output = -1;
	bufferInt = (int) numero;
	if (bufferInt == numero) {
		output = 0;
	}
	return output;
}

/** \brief: funcion que calcula el factorial de un numero
 *
 * \param float numero: el numero a calcular el factorial
 * \return (-1) si no se pudo realizar el factorial, caso contrario se devuelve el factorial calculado
 */
long long int getFactorial(float numero) {
	int esUnFlotante;
	int bufferInt;
	long long int total = -1;
	esUnFlotante = isFloat(numero);
	if (esUnFlotante == 0 && numero >= 0) {
		bufferInt = (int) numero;
		if (numero == 0) {
			total = 1;
		} else {
			total = bufferInt * getFactorial(numero - 1);
		}
	}
	return total;
}

/** \brief: funcion que muestra todos los resultados de las operaciones
 *
 * \param *resultadoOperaciones: el array donde se guarda si cada operaciones fue exitosa (0) o no (-1)
 * \param resultadoFactorialNumeroUno: resultado del factorial del numero 1
 * \param resultadoFactorialNumeroDos: resultado del factorial del numero 2
 * \param contadorNumerosIngresados: la cantidad de numeros que ingreso el usuario desde el MENU principal
 * \param flagCalcularOperaciones: flag que comprueba si se llevo a cabo el paso 3 (CALCULAR OPERACIONES) DEL MENU principal
 * \param resultadoSuma: el resultado de la suma de 2 numeros
 * \param resultadoResta: el resultado de la resta de 2 numeros
 * \param resultadoProducto: el resultado del producto de 2 numeros
 * \param resultadoDivision: el resultado de la division de 2 numeros
 * \return (-1) si no se pudo mostrar los RESULTADOS (0) si los RESULTADOS se mostraron de forma exitosa
 */
int mostrarResultados(int *resultadoOperaciones,
		long long int resultadoFactorialNumeroUno,
		long long int resultadoFactorialNumeroDos,
		int contadorNumerosIngresados, int flagCalcularOperaciones,
		float resultadoSuma, float resultadoResta, float resultadoProducto,
		float resultadoDivision) {

	int output = -1;

	if (contadorNumerosIngresados < 2 || flagCalcularOperaciones != 1) {
		printf("CUIDADO! Resta Cargar un Operando y/o Calcular Operaciones [opcion 3]\n");
	} else {
		printf("####### RESULTADO OPERACIONES #######\n");
		if (resultadoOperaciones[0] == 0) {
			printf("# - Resultado de la SUMA: %.2f\n", resultadoSuma);
		} else {
			printf("# - Error al realizar la SUMA\n");
		}
		if (resultadoOperaciones[1] == 0) {
			printf("# - Resultado de la RESTA: %.2f\n", resultadoResta);
		} else {
			printf("# - Error al realizar la RESTA\n");
		}
		if (resultadoOperaciones[2] == 0) {
			printf("# - Resultado del PRODUCTO: %.2f\n", resultadoProducto);
		} else {
			printf("# - Error al realizar el PRODUCTO\n");
		}
		if (resultadoOperaciones[3] == 0) {
			printf("# - Resultado de la DIVISION: %.2f\n", resultadoDivision);
		} else {
			printf("# - Error al realizar la DIVISION\n");
		}
		if (resultadoFactorialNumeroUno != -1) {
			printf("# - Restulado Factorial Operando A: %lli\n",
					resultadoFactorialNumeroUno);
		} else {
			printf("# - Resultado Factorial Operando A: Error, no se puede realizar facotorial de numeros negativos o flotantes\n");
		}
		if (resultadoFactorialNumeroDos != -1) {
			printf("# - Restulado Factorial Operando B: %lli\n",
					resultadoFactorialNumeroDos);
		} else {
			printf("# - Resultado Factorial Operando B: Error, no se puede realizar facotorial de numeros negativos o flotantes\n");
		}
		output = 0;
	}
	return output;
}
