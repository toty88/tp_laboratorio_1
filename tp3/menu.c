#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

/* ########################## MENUES ##################################*/

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

void printColumn(void){

    char sp = ' ';

    printf(
      "\n##################################################\n"
        "############## LISTA DE EMPLEADOS ################\n"
        "##################################################\n");
    printf("# %1cID%10cNOMBRE%8cHORAS%9cSUELDO\n", sp, sp, sp, sp);
    printf("##################################################\n\n");

}

void printColumnSingleCliente(void){

    char sp = ' ';

    printf(
      "\n##################################################\n"
        "############ DATOS DEL CLIENTE OWNER #############\n"
        "##################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT\n", sp, sp, sp, sp);
    printf("##################################################\n\n");

}

void printColumnPublicacion(void){

    char sp = ' ';

    printf(
      "\n########################################################################################################\n"
        "###################################### LISTA DE PUBLICACIONES ##########################################\n"
        "########################################################################################################\n");
    printf("# %1cID%10cRUBRO%8cESTADO%59cDESCRIPCION\n", sp, sp, sp, sp);
    printf("########################################################################################################\n\n");

}

void printColumnPublicacionesDeUnCliente(void){

    char sp = ' ';

    printf(
      "\n########################################################################################################\n"
        "################################ LISTA DE PUBLICACIONES DEL CLIENTE ####################################\n"
        "########################################################################################################\n");
    printf("# %1cID%10cRUBRO%8cESTADO%59cDESCRIPCION\n", sp, sp, sp, sp);
    printf("########################################################################################################\n");

}

void printColumnClientYpublicacionesActivas(void){

    char sp = ' ';

    printf(
         "\n#####################################################################\n"
           "############ LISTA DE CLIENTE CON PUBLICACIONES ACTIVAS #############\n"
           "#####################################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT%5cAVISOS ACTIVOS\n", sp, sp, sp, sp, sp);
    printf("#####################################################################\n");

}

void printColumnClienteYPublicacion(void){

    char sp = ' ';

    printf(
      "\n#####################################################################################################################################################################\n"
        "####################################################### DETALLE DE CLIENTES Y DETALLE DE PUBLICACIONES ##############################################################\n"
        "#####################################################################################################################################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT %1cID PUBLICACION%10cRUBRO%8cESTADO%59cDESCRIPCION\n", sp, sp, sp, sp, sp, sp, sp, sp);
    printf("#####################################################################################################################################################################\n\n");

}
