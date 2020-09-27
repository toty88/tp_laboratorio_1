#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

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

int reportsEmployeeMenu(int *pResultado){

	int output = -1;
	int opcion;
	if(pResultado != NULL){
		__fpurge(stdin);
		if(!(utn_getInt(
			"\n######################################################\n"
			"############## ABM SUBMENU - INFORMES  ###############\n"
			"######################################################\n"
			"(1). EMPLEADOS ORDENADOS POR NOMBRE Y SECTOR\n"
			"(2). TOTAL Y PROMEDIO DE LOS SALARIOS Y EMPLEADOS POR ENCIMA DEL PROMEDIO\n"
			"(3). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

			*pResultado = opcion;
			output = 0;
		}
	}
	return output;
}

void printColumn(void){

	char sp = ' ';

	printf("\n######################################################\n"
		"################ LISTA DE EMPLEADOS ##################\n"
		"######################################################\n");
	printf("# %1cID%6cFNAME%8cLNAME%5cSECTOR%7cSALARY\n", sp, sp, sp, sp, sp);
	printf("######################################################\n\n");

}

void printColumnAboveAverageSalary(void){

	char sp = ' ';

	printf("\n######################################################\n"
		"################ LISTA DE EMPLEADOS ##################\n"
		"####### CON SALARIOS POR ENCIMA DEL PROMEDIO #########\n"
		"######################################################\n");
	printf("# %1cID%6cFNAME%8cLNAME%5cSECTOR%7cSALARY\n", sp, sp, sp, sp, sp);
	printf("######################################################\n\n");

}

void printColumnSortedEmployees(void){

	char sp = ' ';

	printf("\n######################################################\n"
		"################ LISTA DE EMPLEADOS ##################\n"
		"########### ORDENADOS POR NOMBRE Y SECTOR ############\n"
		"######################################################\n");
	printf("# %1cID%6cFNAME%8cLNAME%5cSECTOR%7cSALARY\n", sp, sp, sp, sp, sp);
	printf("######################################################\n\n");

}
