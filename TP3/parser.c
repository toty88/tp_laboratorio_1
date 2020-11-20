#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief funcion que parsea elementos DESDE un archivo de texto de tipo csv
 *
 * @param pFile el puntero al archivo
 * @param pArrayListEmployee la linked list de empleados
 * @return (1) Error (0) Todo OK
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int output = -1;
    int writtenValues;
    char bufferId[SIZE_NAME];
    char bufferName[SIZE_NAME];
    char bufferHoras[SIZE_NAME];
    char bufferSueldo[SIZE_NAME];
    Employee* aux;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            writtenValues = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoras, bufferSueldo);
            if(writtenValues == 4)
            {
                aux = employee_newParametrosTXT(bufferId, bufferName, bufferHoras, bufferSueldo);
                if(aux != NULL)
                {
                    if(!(ll_add(pArrayListEmployee, aux)))
                    {
                        output = 0;
                    }
                    else
                    {
                        employee_delete(aux);
                    }
                }
            }
        }
        while(!feof(pFile));
    }
    return output;
}

/**
 * @fn int parser_EmployeeToText(FILE*, LinkedList*)
 * @brief funcion que parsea elementos HACIA un archivo de texto de tipo csv
 *
 * @param pFile el puntero al archivo
 * @param pArrayListEmployee la linked list de empleados
 * @return (1) Error (0) Todo OK
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int output = -1;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        int len = ll_len(pArrayListEmployee);
        Employee* aux;
        if(pFile != NULL)
        {
            for(int x = 0; x < len; x++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, x);
                if(aux != NULL)
                {
                    fprintf(pFile, "%d,%s,%d,%.2f\n", employee_getId(aux), employee_getNombre(aux),
                                                    employee_getHorasTrabajadas(aux), employee_getSueldo(aux));
                }
                output = 0;
            }
        }
    }
    return output;
}

/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief funcion que parsea elementos de un archivo de tipo binario
 *
 * @param pFile el puntero al archivo
 * @param pArrayListEmployee la linked list de empleados
 * @return (1) Error (0) Todo OK
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int output = -1;
    int writtenValues;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            Employee* aux = employee_new();
            if(aux != NULL)
            {
                writtenValues = fread(aux, sizeof(Employee), 1, pFile);
                if(writtenValues == 1)
                {
                    if(!(ll_add(pArrayListEmployee, aux)))
                    {
                        output = 0;
                    }
                }
                else
                {
                    employee_delete(aux);
                }
            }
        }
        while(!feof(pFile));
    }
    return output;
}

/**
 * @fn int parser_EmployeeToText(FILE*, LinkedList*)
 * @brief funcion que parsea elementos HACIA un archivo de tipo binario
 *
 * @param pFile el puntero al archivo
 * @param pArrayListEmployee la linked list de empleados
 * @return (1) Error (0) Todo OK
 */
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int output = -1;
    int writtenValues;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        Employee* aux;
        if(pFile != NULL)
        {
            for(int x = 0; x < ll_len(pArrayListEmployee); x++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, x);
                if(aux != NULL)
                {
                    writtenValues = fwrite(aux, sizeof(Employee),1,pFile);
                    if(writtenValues == 1)
                    {
                        output = 0;
                    }
                }
            }
        }
    }
    return output;
}


