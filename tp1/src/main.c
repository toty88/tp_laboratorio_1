#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include<ctype.h>
#include<string.h>
#include"funciones.h"
#include"menu.h"

int main(void){
	int resultadoOperacion;
	int resultadoOperaciones[4];
    float numero1 = 0;
	float numero2 = 0;
	unsigned int flagMenu = 0;
	unsigned int flagCalcularOperaciones = 0;
	unsigned int opcion; 
	unsigned int contadorNumerosIngresados = 0;
	float resultadoSuma, resultadoResta, resultadoProducto, resultadoDivision;
	long long int resultadoFactorialNumeroUno, resultadoFactorialNumeroDos;
	do{
		opcion = mainMenu(flagMenu, numero1, numero2);
		switch(opcion){
			case 1:
				resultadoOperacion = getFloat("\nIngrese Operando A: ", "Error, reintentos", &numero1, 3);
				if(resultadoOperacion == 0){
					printf("Primer operando cargado con exito\n");
					if(flagMenu !=2){
						flagMenu = 1;
					}
					contadorNumerosIngresados++;
				}else{
					printf("No se pudo cargar operando, vuelva a intentar\n");
					if(flagMenu != 2){
						flagMenu = 0;
					}
				}
				break;
			case 2:
				resultadoOperacion = getFloat("\nIngrese Operando B: ", "Error, reintentos", &numero2, 3);
				if(resultadoOperacion == 0){
					printf("Segundo operando cargado con exito\n");
					flagMenu = 2;
					contadorNumerosIngresados++;
				}else{
					printf("No se pudo cargar operando, vuelva a intentar\n");
					if(flagMenu != 1){
						flagMenu = 0;
					}
				}
				break;
			case 3:
				if(contadorNumerosIngresados < 2){
					printf("CUIDADO! Resta cargar un Operando\n");
				}else{
					resultadoOperaciones[0] = getSum(&resultadoSuma, numero1, numero2);
					resultadoOperaciones[1] = getSubtraction(&resultadoResta, numero1, numero2);
					resultadoOperaciones[2] = getProduct(&resultadoProducto, numero1, numero2);
					resultadoOperaciones[3] = getDivision(&resultadoDivision, numero1, numero2);
					resultadoFactorialNumeroUno = getFactorial(numero1);
					resultadoFactorialNumeroDos = getFactorial(numero2);
					flagCalcularOperaciones = 1;
					printf("Operaciones realizadas\n");
				}
				break;
			case 4:
				resultadoOperacion = mostrarResultados(resultadoOperaciones, resultadoFactorialNumeroUno, resultadoFactorialNumeroDos, contadorNumerosIngresados, flagCalcularOperaciones, resultadoSuma, resultadoResta, resultadoProducto, resultadoDivision);
				if(resultadoOperacion == -1){
					printf("ERROR AL MOSTRAR RESULTADOS\n");
				}
				break;
			case 5:
				printf("Ha salido de la Calculadora\n");
				break;
			default:
				printf("Opcion invalida. Intente de nuevo\n");
		}
		printf("\nPress any key to continue");
		__fpurge(stdin); 
		getchar();
		system("clear");
	}while(opcion != 5);
	return 0;
}
