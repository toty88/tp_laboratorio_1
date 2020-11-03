#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
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
                }
            }
        }
        while(!feof(pFile));
    }
    return output;
}

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

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
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
            }
        }
        while(!feof(pFile));
    }
    return output;
}

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


