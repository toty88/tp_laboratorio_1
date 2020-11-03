#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"LinkedList.h"
#include"Controller.h"
#include"Employee.h"
/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/
int main()
{
    int mainMenuOption;
    int bufferOutput;
    int flagCaseOne = 0;
    int flagCaseTwo = 0;
    char bufferFileName[SIZE_NAME];
    LinkedList *listaEmpleados = ll_newLinkedList();
    do
    {
        if (!(menu_Main(&mainMenuOption)))
        {
            switch (mainMenuOption)
            {
            case 1:
                if(!(utn_getString("Ingrese nombre archivo: ", "Error, reintentos", bufferFileName, SIZE_NAME, 3))
                        && !(controller_loadFromText(bufferFileName, listaEmpleados)))
                {
                    printf("\n >>>>> EMPLEADOS FORMATO TEXTO IMPORTADOS CON EXITO <<<<<\n");
                    flagCaseOne = 1;

                }
                else
                {
                    printf("\n >>>>> ARCHIVO NO ENCONTRADO, CORROBORE NOMBRE <<<<<\n");
                }
                break;
            case 2:
                if(!(utn_getString("Ingrese nombre archivo: ", "Error, reintentos", bufferFileName, SIZE_NAME, 3))
                        && !(controller_loadFromBinary(bufferFileName, listaEmpleados)))
                {
                    printf("\n >>>>> EMPLEADOS FORMATO TEXTO IMPORTADOS CON EXITO <<<<<\n");
                    flagCaseOne = 2;

                }
                break;
            case 3:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    if(!(controller_addEmployee(listaEmpleados)))
                    {
                        printf("\n >>>>> EMPLEADO AGREGADO CON EXITO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 4:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    bufferOutput = controller_editEmployee(listaEmpleados);
                    if(bufferOutput == 0)
                    {
                        printf("\n >>>>> EMPLEADO MODIFICADO CON EXITO <<<<<\n");
                    }
                    else if(bufferOutput == 1)
                    {
                        printf("\n >>>>> NO SE REALIZO NINGUNA MODIFICACION <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER MODIFICAR EMPLEADO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 5:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    bufferOutput = controller_removeEmployee(listaEmpleados);
                    if(bufferOutput == 0)
                    {
                        printf("\n >>>>> EMPLEADO DADO DE BAJA CON EXITO <<<<<\n");
                    }
                    else if(bufferOutput == 1)
                    {
                        printf("\n >>>>> NO SE REALIZO NINGUNA BAJA <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER DAR DE BAJA UN EMPLEADO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 6:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    if(!(controller_ListEmployee(listaEmpleados)))
                    {
                        printf("\n >>>>> EMPLEADOS LISTADOS CON EXITO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 7:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    if(!(controller_sortEmployee(listaEmpleados)))
                    {
                        printf("\n >>>>> EMPLEADOS ORDENADOS CON EXITO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 8:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    if(!(controller_saveAsText("data.csv", listaEmpleados)))
                    {
                        printf("\n >>>>> EMPLEADOS GUARDADOS EN TEXTO CON EXITO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 9:
                if(flagCaseOne == 1 || flagCaseTwo == 1)
                {
                    if(!(controller_saveAsBinary("data.bin", listaEmpleados)))
                    {
                        printf("\n >>>>> EMPLEADOS GUARDADOS EN BINARIO CON EXITO <<<<<\n");
                    }
                }
                else
                {
                    printf("\n >>>>> OPCION NO DISPONIBLE, PRIMERO IMPORTE EMPLEADOS (OPCION 1 O 2) <<<<<\n");
                }
                break;
            case 10:
                printf("\n >>>>> HA SALIDO, HASTA LUEGO <<<<<\n");
                break;
            default:
                printf("\n >>>>> OPCION INVALIDA, VUELVA A INTENTAR <<<<<\n");
            }
        }
    }
    while (mainMenuOption != 10);
    return 0;
}

