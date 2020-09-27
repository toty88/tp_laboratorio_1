#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ArrayEmployees.h"

int hardcodeArrayEmployees(Employee* arrayEmployees) {
	int output = -1;
	int bufferID[5] = { 100, 101, 102, 103, 104};
	char bufferName[5][SIZE_NAMES] = { "BON", "ANGUS", "BRIAN", "RICARDO", "BRUCE"};
	char bufferLastName[5][SIZE_NAMES] = { "SCOTT", "YOUNG", "JHONSON", "IORIO", "DICIKINSON"};
	float bufferSalary[5] = {800, 900, 1000, 2300, 5100};
	int bufferSector[5] = {1, 2, 3, 4, 5};

	if (arrayEmployees != NULL) {
		for (int x = 0; x < 5; x++) {
			strncpy(arrayEmployees[x].name, bufferName[x], SIZE_NAMES);
			strncpy(arrayEmployees[x].lastName, bufferLastName[x], SIZE_NAMES);
			arrayEmployees[x].sector = bufferSector[x];
			arrayEmployees[x].salary = bufferSalary[x];
			arrayEmployees[x].id = bufferID[x];
			arrayEmployees[x].isEmpty = FALSE;
		}
		output = 0;
	}
	return output;
}

int initEmployees(Employee* arrayEmployees, int len){
	int output = -1;
	if(arrayEmployees != NULL && len > 0){
		for(int x = 0; x < len; x++){
			arrayEmployees[x].isEmpty = TRUE;
		}
		output = 0;
	}
	return output;
}

int findEmployeeById(Employee* arrayEmployees, int len, int id, int* indexPosition){

	int output = -1;
	if(arrayEmployees != NULL && indexPosition != NULL && len > 0 && id > 0){
		for(int x = 0; x < len; x++){
			if(arrayEmployees[x].id == id && arrayEmployees[x].isEmpty == FALSE){
				*indexPosition = x;
				output = 0;
				break;
			}
		}
	}
	return output;
}

int findFirstFreePosition(Employee* arrayEmployees, int len, int* freeIndexPosition){
	int output = -1;
	if(arrayEmployees != NULL && freeIndexPosition != NULL && len > 0){
		for(int x = 0; x < len; x++){
			if(arrayEmployees[x].isEmpty == TRUE){
				*freeIndexPosition = x;
				output = 0;
				break;
			}
		}
	}
	return output;
}

static int getEmployeeID(int* employeeID){

	int output = -1;
	static int id = 105;
	if(employeeID != NULL){
		*employeeID = id++;
		output = 0;
	}
	return output;
}

int createEmployee(Employee* arrayEmployees, int len){

	int output = -1;
	Employee bufferEmployee;
	int bufferFreeIndexPosition;

	if(arrayEmployees != NULL && len > 0 && !(findFirstFreePosition(arrayEmployees, len, &bufferFreeIndexPosition))){
		if(!(utn_getString("\n(a). Ingrese nombre: ", "Error, reintentos", bufferEmployee.name, SIZE_NAMES, 3))
			&& !(utn_getString("(b). Ingrese apellido: ", "Error, reintentos", bufferEmployee.lastName, SIZE_NAMES, 3))
			&& !(utn_getFloat("(c). Ingrese salario: ", "Error, reintentos", &bufferEmployee.salary, 3))
			&& !(utn_getInt("(d). Ingrese sector: ", "Error, reintentos", &bufferEmployee.sector, 3))
			&& !(getEmployeeID(&bufferEmployee.id))
			&& !(addEmployees(arrayEmployees, len, bufferEmployee.id, bufferEmployee.name, bufferEmployee.lastName,
			bufferEmployee.salary, bufferEmployee.sector, bufferFreeIndexPosition))){

			output = 0;
		}
	}
	return output;
}

int addEmployees(Employee* arrayEmployees, int len, int id, char* name, char* lastName, float salary, int sector, int freeIndexPosition){

	int output = -1;

	if(arrayEmployees != NULL && name != NULL && lastName != NULL && len > 0 && id > 0 && salary > 0 && sector > 0){

		arrayEmployees[freeIndexPosition].sector = sector;
		arrayEmployees[freeIndexPosition].salary = salary;
		arrayEmployees[freeIndexPosition].id = id;
		strcpy(arrayEmployees[freeIndexPosition].name, name);
		strcpy(arrayEmployees[freeIndexPosition].lastName, lastName);
		arrayEmployees[freeIndexPosition].isEmpty = FALSE;
		output = 0;
	}
	return output;
}

/** \brief: funcion que modifica un empleado en base a un ID
 *
 * \param Employee* arrayEmployees: el array de empleados
 * \param int len: el size del array de empleados
 * \return (-1) si hubo error - (1) si no hubo modificaciones - (0) si la modificacion fue exitosa
 */
int modifyEmployees(Employee* arrayEmployees, int len){
	int output = -1;
	int opcionMenuModificaciones;
	int flag;
	int bufferID;
	int bufferIndex;
	Employee bufferEmployee;

	if(arrayEmployees != NULL && len > 0){
		do{
			if(!(modifyEmployeeMenu(&opcionMenuModificaciones))){
				switch(opcionMenuModificaciones){
				case 1:
					if(!printEmployees(arrayEmployees, len)){
						output = 1;
					}
					break;
				case 2:
					if(!(utn_getInt("\nIngrese ID del empleado a modificar: ", "Error, reintentos", &bufferID, 3))){
						if(findEmployeeById(arrayEmployees, len, bufferID, &bufferIndex)){
							printf("ID INVALIDO, VUELVA A LISTAR EMPLEADOS O SALGA\n");
						}else{
							flag = 1;
						}
						output = 1;
					}
					break;
				case 3:
					if(flag == 1){
						if(!(utn_getString("\n(a). Ingrese nuevo nombre: ", "Error, reintentos", bufferEmployee.name, SIZE_NAMES, 3))){
							strncpy(arrayEmployees[bufferIndex].name, bufferEmployee.name, SIZE_NAMES);
							output = 0;
						}
					}else{
						printf("DEBE INGRESAR ID PRIMERO\n");
						output = 1;
					}
					break;
				case 4:
					if(flag == 1){
						if(!(utn_getString("(b). Ingrese nuevo apellido: ", "Error, reintentos", bufferEmployee.lastName, SIZE_NAMES, 3))){
							strncpy(arrayEmployees[bufferIndex].lastName, bufferEmployee.lastName, SIZE_NAMES);
							output = 0;
						}
					}else{
						printf("DEBE INGRESAR ID PRIMERO\n");
						output = 1;
					}
					break;
				case 5:
					if(flag == 1){
						if(!(utn_getFloat("(c). Ingrese nuevo salario: ", "Error, reintentos", &bufferEmployee.salary, 3))){
							arrayEmployees[bufferIndex].salary = bufferEmployee.salary;
							output = 0;
						}
					}else{
						printf("DEBE INGRESAR ID PRIMERO\n");
						output = 1;
					}
					break;
				case 6:
					if(flag == 1){
						if(!!(utn_getInt("(d). Ingrese nuevo sector: ", "Error, reintentos", &bufferEmployee.sector, 3))){
							arrayEmployees[bufferIndex].sector = bufferEmployee.sector;
							output = 0;
						}
					}else{
						printf("DEBE INGRESAR ID PRIMERO\n");
						output = 1;
					}
					break;
				case 7:
					printf("SALIENDO AL MENU PRINCIPAL\n");
					break;
				default:
					printf("ERROR, OPCION INVALIDA\n");
				}
			}
		printf("\nPresione una tecla para continuar");
		__fpurge(stdin);
		getchar();
		system("clear");
		}while(opcionMenuModificaciones != 7);
	}
	return output;
}

/** \brief: funcion que elimina un empleado en base a un ID
 *
 * \param Employee* arrayEmployees: el array de empleados
 * \param int len: el size del array de empleados
 * \return (-1) si hubo error - (1) si no se elimino empleado - (0) si la eliminacion fue exitosa
 */
int removeEmployee(Employee* arrayEmployees, int len){
	int output = -1;
	int opcionMenuBaja;
	int confirmaEliminacion;
	int bufferID;
	int bufferIndex;

	if(arrayEmployees != NULL && len > 0){
		do{
			if(!(removeEmployeeMenu(&opcionMenuBaja))){
				switch(opcionMenuBaja){
				case 1:
					if(printEmployees(arrayEmployees, len)){
						printf("ERROR AL LISTAR EMPLEADOS\n");
						opcionMenuBaja = 7;
					}
					break;
				case 2:
					if(!(utn_getInt("\nIngrese ID del empleado a eliminar: ", "Error, reintentos", &bufferID, 3))){
						if(findEmployeeById(arrayEmployees, len, bufferID, &bufferIndex)){
							printf("ID INVALIDO, VUELVA A LISTAR EMPLEADOS O SALGA\n");
							output = 1;
						}else{
							printf("CONFIRMAR BAJA %s %s\n", arrayEmployees[bufferIndex].name, arrayEmployees[bufferIndex].lastName);
							if(!utn_getInt("(1). CONFIRMAR\n(2). CANCELAR: ", "Error, reintentos", &confirmaEliminacion, 3)){
								if(confirmaEliminacion == 1){
									arrayEmployees[bufferIndex].isEmpty = TRUE;
									output = 0;
								}else if(confirmaEliminacion == 2){
									output = 1;

								}else{
									printf("OPCION INVALIDA\n");
								}
							}
						}
					}
					break;
				case 3:
					printf("SALIENDO AL MENU PRINCIPAL\n");
					break;
				default:
					printf("ERROR, OPCION INVALIDA\n");
				}
			}
		printf("\nPresione una tecla para continuar");
		__fpurge(stdin);
		getchar();
		system("clear");
		}while(opcionMenuBaja != 3);
	}
	return output;
}

void printOneEmployee(Employee employee){

	printf("# %d %10s %12s %10d %12.2f\n",
			employee.id,
			employee.name,
			employee.lastName,
			employee.sector,
			employee.salary);
}

int printEmployees(Employee* arrayEmployees, int len){
	int output = -1;
	if(arrayEmployees != NULL && len > 0){
		printColumn();
		for(int x = 0; x < len; x++){
			if(arrayEmployees[x].isEmpty == FALSE){
				printOneEmployee(arrayEmployees[x]);
			}
		}
		output = 0;
	}
	return output;
}

int getEmployeesAverageSalary(Employee* arrayEmployees, int len, float *pSalarioPromedio, float *pTotalSalarios){

	int output = -1;
	float bufferTotalSalary = 0;
	int bufferTotalAmountOfEmployees = 0;
	if(arrayEmployees != NULL && pSalarioPromedio != NULL && pTotalSalarios != NULL && len > 0){

		for(int x = 0; x < len; x++){
			if(arrayEmployees[x].isEmpty == FALSE){
				bufferTotalSalary += arrayEmployees[x].salary;
				bufferTotalAmountOfEmployees++;
			}
		}
		if(bufferTotalAmountOfEmployees > 0){
			*pTotalSalarios = bufferTotalSalary;
			*pSalarioPromedio = bufferTotalSalary/bufferTotalAmountOfEmployees;
			output = 0;
		}
	}
	return output;
}

int getEmployeesAboveAverageSalary(Employee* arrayEmployees, int len, int salarioPromedio){

	int output = -1;
	if(arrayEmployees != NULL && len > 0 && salarioPromedio > 0){
		printColumnAboveAverageSalary();
		for(int x = 0; x < len; x++){
			if(arrayEmployees[x].salary > salarioPromedio){
				printOneEmployee(arrayEmployees[x]);
			}
		}
		output = 0;
	}
	return output;

}

int sortEmployees(Employee* arrayEmployees, int len, int order){
	int output = -1;
	int flag = 1;
	Employee bufferEmployee;
	if(arrayEmployees != NULL && len > 0){
		if(order == 1){
			while(flag){
				flag = 0;
				for(int x = 0; x < (len-1); x++){
					if(strcmp(arrayEmployees[x].name, arrayEmployees[x+1].name) > 0
						&& (arrayEmployees[x].sector > arrayEmployees[x+1].sector)){
						bufferEmployee = arrayEmployees[x];
						arrayEmployees[x] = arrayEmployees[x+1];
						arrayEmployees[x+1] = bufferEmployee;
						flag = 1;
						output = 0;
					}
				}
			}

		}else{
			while(flag){
				flag = 0;
				for(int x = 0; x < (len-1); x++){
					if(strcmp(arrayEmployees[x].name, arrayEmployees[x+1].name) < 0
						&& (arrayEmployees[x].sector < arrayEmployees[x+1].sector)){
						bufferEmployee = arrayEmployees[x];
						arrayEmployees[x] = arrayEmployees[x+1];
						arrayEmployees[x+1] = bufferEmployee;
						flag = 1;
						output = 0;
					}
				}
			}

		}
	}
	return output;
}

int reportsEmployees(Employee* arrayEmployees, int len){

	int output = -1;
	int order;
	float bufferAverageSalary;
	float bufferSalarySum;
	int opcionMenuInformes;

	if(arrayEmployees != NULL && len > 0){
		do{
			if(!(reportsEmployeeMenu(&opcionMenuInformes))){
				switch(opcionMenuInformes){
				case 1:
					if(!(utn_getInt(
						"\n(1). ORDENAR POR NOMBRE Y SECTOR DE FORMA ASCENDENTE\n"
						"(2). ORDENAR POR NOMBRE Y SECTOR DE FORMA DESCENDENTE: ", "ERROR, REINTENTOS", &order, 3))
						&& !(sortEmployees(arrayEmployees, len, order))){
						printEmployees(arrayEmployees, len);
						output = 0;
					}
					break;
				case 2:
					if(!(getEmployeesAverageSalary(arrayEmployees, len, &bufferAverageSalary, &bufferSalarySum))){
						printf("\nSALARIO TOTAL DE EMPLEADOS: %.2f\nSALARIO PROMEDIO DE EMPLEADOS: %.2f\n", bufferSalarySum, bufferAverageSalary);
						if(!(getEmployeesAboveAverageSalary(arrayEmployees, len, bufferAverageSalary))){
							output = 0;
						}
					}else{
						printf("HUBO UN ERROR AL CALCULAR SALARIOS & PROMEDIOS\n");
					}
					break;
				case 3:
					printf("SALIENDO AL MENU PRINCIPAL\n");
					break;
				default:
					printf("ERROR, OPCION INVALIDA\n");
				}
			}
		printf("\nPresione una tecla para continuar");
		__fpurge(stdin);
		getchar();
		system("clear");
		}while(opcionMenuInformes != 3);
	}
	return output;
}

