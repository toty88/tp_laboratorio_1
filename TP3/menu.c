#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

/* ########################## MENUES ##################################*/

/**
 * @fn int menu_Main(int*)
 * @brief funcion que despliega un menu principal
 *
 * @param pResultado puntero int donde se guardara la opcion elgida por el usuario
 * @return (-1) Error (0) Todo OK
 */
int menu_Main(int *pResultado)
{
    int output = -1;
    int opcion;
    if (pResultado != NULL)
    {
        if (!(utn_getInt(
              "\n######################################################\n"
                "############### MENU NOMINA EMPLEADOS ################\n"
                "######################################################\n"
                "(1).  CARGAR DATOS DESDE DATA.CSV (MODO TEXTO)\n"
                "(2).  CARGAR DATOS DESDE DATA.CSV (MODO BINARIO)\n"
                "(3).  ALTA DE EMPLEADO\n"
                "(4).  MODIFICAR DATOS EMPLEADO\n"
                "(5).  BAJA DE EMPLEADO\n"
                "(6).  LISTAR EMPLEADOS\n"
                "(7).  ORDENAR EMPLEADOS\n"
                "(8).  GUARDAR DATOS EMPLEADOS EN DATA.CSV (MODO TEXTO)\n"
                "(9).  GUARDAR DATOS EMPLEADOS EN DATA.CSV (MODO BINARIO)\n"
                "(10). SALIR -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3)))
        {
            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int menu_Main(int*)
 * @brief funcion que despliega un menu de modificaciones de empleado
 *
 * @param pResultado puntero int donde se guardara la opcion elgida por el usuario
 * @return (-1) Error (0) Todo OK
 */
int menu_ModifyEmployee(int *pResultado)
{
    int output = -1;
    int opcion;
    if(pResultado != NULL)
    {
        if(!(utn_getInt(
                      "\n######################################################\n"
                        "################### MENU MODIFICAR ###################\n"
                        "######################################################\n"
                        "(1). LISTAR CLIENTES\n"
                        "(2). INGRESE ID DE CLIENTE\n"
                        "(3). MODIFICAR NOMBRE\n"
                        "(4). MODIFICAR HORAS TRABAJADAS\n"
                        "(5). MODIFICAR SUELDO\n"
                        "(6). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3)))
        {
            *pResultado = opcion;
            output = 0;
            }
    }
    return output;
}

/**
 * @fn int menu_Main(int*)
 * @brief funcion que despliega un menu de eliminacion de empleado
 *
 * @param pResultado puntero int donde se guardara la opcion elgida por el usuario
 * @return (-1) Error (0) Todo OK
 */
int menu_RemoveEmployee(int *pResultado)
{
    int output = -1;
    int opcion;
    if(pResultado != NULL)
    {
        __fpurge(stdin);
        if(!(utn_getInt(
          "\n######################################################\n"
            "##################### MENU BAJA ######################\n"
            "######################################################\n"
            "(1). LISTAR EMPLEADOS\n"
            "(2). INGRESAR ID EMPLEADO\n"
            "(3). CONFIRMAR BAJA EMPLEADO\n"
            "(4). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3)))
        {
            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int menu_Main(int*)
 * @brief funcion que despliega un menu de ordenamiento de empleados
 *
 * @param pResultado puntero int donde se guardara la opcion elgida por el usuario
 * @return (-1) Error (0) Todo OK
 */
int menu_SortEmployee(int *pResultado)
{
    int output = -1;
    int opcion;
    if(pResultado != NULL)
    {
        if(!(utn_getInt(""
                      "\n######################################################\n"
                        "################# MENU ORDENAMIENTO ##################\n"
                        "######################################################\n"
                        "(1). ORDENAR EMPLEADOS POR ID\n"
                        "(2). ORDENAR EMPLEADOS POR NOMBRE\n"
                        "(3). ORDENAR EMPLEADOS POR SUELDO\n"
                        "(4). ORDENAR EMPLEADOS POR HORAS TRABJADAS\n"
                        "(5). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3)))
        {
            *pResultado = opcion;
            output = 0;
        }

    }
    return output;
}

/* ########################## PRINTS ##################################*/

/**
 * @fn void printColumn(void)
 * @brief funcion que imprime cabecera antes de listar empleados
 *
 */
void printColumn(void){

    char sp = ' ';

    printf(
      "\n##########################################################################\n"
        "########################### LISTA DE EMPLEADOS ###########################\n"
        "##########################################################################\n");
    printf("# %3cID%17cNOMBRE%17cHORAS%15cSUELDO\n", sp, sp, sp, sp);
    printf("##########################################################################\n\n");

}



