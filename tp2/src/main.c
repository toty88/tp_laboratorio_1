#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"menu.h"
#include"ArrayEmployees.h"

/* Testeado en:     Linux archlinux
 * Kernel:          5.9.8-arch1-
 * Version GCC:     gcc version 10.2.0 (GCC)
 * Sin Warnings, Sin Errores
 */

int main(void){

	int opcionMenuPrincipal;
	int resultado;
	Employee arrayEmployees[SIZE_ARRAY_EMPLOYEES];
	initEmployees(arrayEmployees, SIZE_ARRAY_EMPLOYEES);
	hardcodeArrayEmployees(arrayEmployees);
	unsigned int flagAlta = 1; // (1) se puede ver el hardcodeo sin necesidad de alta (0) se precisa un alta para ver los usuarios hardcodeados
	do{
		if(!(mainMenu(&opcionMenuPrincipal))){
			switch(opcionMenuPrincipal){
				case 1:
					if(!(createEmployee(arrayEmployees, SIZE_ARRAY_EMPLOYEES))){
						printf("ALTA EXITOSA\n");
						flagAlta = 1;
					}else{
						printf("OCURRIO UN ERROR EN EL ALTA\n");
					}
					break;
				case 2:
					if(flagAlta){
					    resultado = modifyEmployees(arrayEmployees, SIZE_ARRAY_EMPLOYEES);
                        if(resultado == 0){
                            printf("MODIFICACION EXITOSA\n");
                        }else if(resultado == 1){
                            printf("NO SE REALIZO NINGUNA MODIFICACION\n");
                        }else{
                            printf("OCURRIO UN ERROR\n");
                        }
					}else{
					    printf("\nPRIMERO DEBE REALIZAR LA CARGA DE AL MENOS UN EMPLEADO\n");
					}
					break;
				case 3:
				    if(flagAlta){
                        resultado = removeEmployee(arrayEmployees, SIZE_ARRAY_EMPLOYEES);
                        if(resultado == 0){
                            printf("BAJA EXITOSA\n");
                        }else if(resultado == 1){
                            printf("NO SE REALIZO NINGUNA BAJA\n");
                        }else{
                            printf("OCURRIO UN ERROR\n");
                        }
				    }else{
                        printf("\nPRIMERO DEBE REALIZAR LA CARGA DE AL MENOS UN EMPLEADO\n");
                    }
					break;
				case 4:
				    if(flagAlta){
                        if(reportsEmployees(arrayEmployees, SIZE_ARRAY_EMPLOYEES)){
                            printf("ERROR AL LISTAR EMPLEADOS\n");
                        }
				    }else{
                        printf("\nPRIMERO DEBE REALIZAR LA CARGA DE AL MENOS UN EMPLEADO\n");
                    }
					break;
				case 5:
					printf("HA SALIDO, ADIOS!\n");
					break;
				default:
					printf("OPCION INVALIDA, INTENTE DE NUEVO\n");
			}// fin SWITCH
			if(!(opcionMenuPrincipal != 1)){
				printf("\nPresione una tecla para continuar");
				__fpurge(stdin);
				getchar();
				system("clear");
			}
		}else{
			printf("NO SE HA PODIDO VALIDAR NINGUNA OPCION.\nABM TERMINADO");
			opcionMenuPrincipal = 5;
		}
	}while(opcionMenuPrincipal != 5); // fin DO WHILE
	return 0;
}
