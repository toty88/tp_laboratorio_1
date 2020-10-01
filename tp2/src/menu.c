#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

/**
 * @fn int mainMenu(int*)
 * @brief Menu principal que se muestra al iniciar el programa
 *
 * @param pResultado: EL puntero a int que guarda la opcion elegida por el usuario
 * @return (-1) Error, (0) todo OK
 */
int mainMenu(int *pResultado) {

	int output = -1;
	int opcion;
	if (pResultado != NULL) {
		__fpurge(stdin);
		if (!(utn_getInt(
				"\n######################################################\n"
				"########### ABM EMPLEADOS - MENU PRINCIPAL  ##########\n"
				"######################################################\n"
				"(1). ALTA EMPLEADO\n"
				"(2). MODIFICAR EMPLEADO\n"
				"(3). BAJA EMPLEADO\n"
				"(4). INFORMES\n"
				"(5). SALIR -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))) {

			*pResultado = opcion;
			output = 0;
		}
	}
	return output;
}

/**
 * @fn int modifyEmployeeMenu(int*)
 * @brief Menu de Modificaciones que se muestra al elegir la opcion 2 del Menu Principal
 *
 * @param pResultado: EL puntero a int que guarda la opcion elegida por el usuario
 * @return (-1) Error, (0) todo OK
 */
int modifyEmployeeMenu(int *pResultado) {

	int output = -1;
	int opcion;
	if(pResultado != NULL){
		__fpurge(stdin);
		if(!(utn_getInt("\n######################################################\n"
						"######### ABM SUBMENU - MODIFICAR EMPLEADO  ##########\n"
						"######################################################\n"
						"(1). LISTAR EMPLEADOS\n"
						"(2). INGRESAR ID DEL EMPLEADO A MOFICIAR\n"
						"(3). MODIFICAR NOMBRE\n"
						"(4). MODIFICAR APELLIDO\n"
						"(5). MODIFICAR SALARIO\n"
						"(6). MODIFICAR SECTOR\n"
						"(7). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

			*pResultado = opcion;
			output = 0;
			}
	}
	return output;
}

/**
 * @fn int removeEmployeeMenu(int*)
 * @brief Menu de Bajas que se muestra al elegir la opcion 3 del Menu Principal
 *
 * @param pResultado: EL puntero a int que guarda la opcion elegida por el usuario
 * @return (-1) Error, (0) todo OK
 */
int removeEmployeeMenu(int *pResultado){

	int output = -1;
	int opcion;
	if(pResultado != NULL){
		__fpurge(stdin);
		if(!(utn_getInt("\n######################################################\n"
						"########## ABM SUBMENU - ELIMINAR EMPLEADO  ##########\n"
						"######################################################\n"
						"(1). LISTAR EMPLEADOS\n"
						"(2). INGRESAR ID DEL EMPLEADO A ELIMINAR\n"
						"(3). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

			*pResultado = opcion;
			output = 0;
		}

	}
	return output;
}

/**
 * @fn int reportsEmployeeMenu(int*)
 * @brief Menu de Informes que se muestra al elegir la opcion 4 del Menu Principal
 *
 * @param pResultado: EL puntero a int que guarda la opcion elegida por el usuario
 * @return (-1) Error, (0) todo OK
 */
int reportsEmployeeMenu(int *pResultado){

	int output = -1;
	int opcion;
	if(pResultado != NULL){
		__fpurge(stdin);
		if(!(utn_getInt(
			"\n######################################################\n"
			"############## ABM SUBMENU - INFORMES  ###############\n"
			"######################################################\n"
		    "(1). LISTAR EMPLEADOS\n"
			"(2). LISTAR EMPLEADOS ORDENADOS POR APELLIDO Y SECTOR\n"
			"(3). (#). TOTAL Y PROMEDIO DE LOS SALARIOS\n"
			"     (#). EMPLEADOS POR ENCIMA DEL PROMEDIO\n"
			"(4). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

			*pResultado = opcion;
			output = 0;
		}
	}
	return output;
}

/**
 * @fn void printColumn(void)
 * @brief Funcion que imprime encabezado al listar empleados
 *
 */
void printColumn(void){

	char sp = ' ';

	printf("\n######################################################\n"
		"################ LISTA DE EMPLEADOS ##################\n"
		"######################################################\n");
	printf("# %1cID%6cAPELLIDO%8cNOMBRE%5cSECTOR%7cSALARIO\n", sp, sp, sp, sp, sp);
	printf("######################################################\n\n");

}

/**
 * @fn void printColumnAboveAverageSalary(void)
 * @brief Funcion que imprime encabezado al listar empleados por encima del salario promedio
 *
 */
void printColumnAboveAverageSalary(void){

	char sp = ' ';

	printf("\n######################################################\n"
		"################ LISTA DE EMPLEADOS ##################\n"
		"####### CON SALARIOS POR ENCIMA DEL PROMEDIO #########\n"
		"######################################################\n");
	printf("# %1cID%6cAPELLIDO%8cNOMBRE%5cSECTOR%7cSALARIO\n", sp, sp, sp, sp, sp);
	printf("######################################################\n\n");

}

/**
 * @fn void printColumnSortedEmployees(void)
 * @brief Funcion que imprime encabezado al listar empleados ordenados
 *
 */
void printColumnSortedEmployees(void){

	char sp = ' ';

	printf("\n######################################################\n"
		"################ LISTA DE EMPLEADOS ##################\n"
		"########### ORDENADOS POR NOMBRE Y SECTOR ############\n"
		"######################################################\n");
	printf("# %1cID%6cAPELLIDO%8cNOMBRE%5cSECTOR%7cSALARIO\n", sp, sp, sp, sp, sp);
	printf("######################################################\n\n");

}
