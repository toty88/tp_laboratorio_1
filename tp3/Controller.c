#include"Controller.h"


static int employee_generateId(LinkedList* pArrayListEmployee, int*);

static int employee_generateId(LinkedList* pArrayListEmployee, int *id) {

    int output = -1;
    static int bufferId;
    if (id != NULL && !(employee_findMaxId(pArrayListEmployee, &bufferId)))
    {
        bufferId++;
        *id = bufferId;
        output = 0;
    }
    return output;
}

int employee_findMaxId(LinkedList* pArrayListEmployee, int *id)
{
    int output = -1;
    int bufferMaxId;
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        for(int x = 0; x < ll_len(pArrayListEmployee); x++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee, x);
            if(aux != NULL)
            {
                if(aux->id > bufferMaxId || x == 0)
                {
                    bufferMaxId = aux->id;
                }
                *id = bufferMaxId;
                output = 0;
            }
        }
    }
    return output;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* in;
    int output = -1;
    in = fopen(path, "r");
    if(in != NULL)
    {
        if(!(parser_EmployeeFromText(in, pArrayListEmployee)))
        {
            output = 0;
        }
        fclose(in);
    }
    return output;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* in;
    int output = -1;
    in = fopen(path, "rb");
    if(in != NULL)
    {
        if(!(parser_EmployeeFromBinary(in, pArrayListEmployee)))
        {
            output = 0;
        }
        fclose(in);
    }
    return output;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int output = -1;
    int bufferId;
    char bufferName[SIZE_NAME];
    int bufferHoras;
    float bufferSueldo;

    if(pArrayListEmployee != NULL)
    {
        if(!(employee_generateId(pArrayListEmployee, &bufferId)) && !(utn_getString("Ingrese nombre: ", "Error,  reintentos", bufferName, SIZE_NAME, 3))
                && !(utn_getInt("Ingrese horas trabajadas: ", "Error, reintentos", &bufferHoras, 3))
                && !(utn_getFloat("Ingrese sueldo: ", "Error, reintentos", &bufferSueldo, 3)))
        {
            Employee* aux = employee_newParam(bufferId, bufferName, bufferHoras, bufferSueldo);
            if(aux != NULL && !(ll_add(pArrayListEmployee, aux)))
            {

                output = 0;
            }
        }
    }
    return output;
}

int employee_findById(LinkedList* pArrayListEmployee, int id, int *indexPosition)
{
    int output = -1;
    Employee* aux;
    if (pArrayListEmployee != NULL && indexPosition != NULL && id > 0)
    {
        for (int x = 0; x < ll_len(pArrayListEmployee); x++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee, x);
            if (employee_getId(aux) == id)
            {
                *indexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int output = -1;
    int modifyOption;
    int bufferId;
    int bufferIndex;
    Employee* pBufferAux;
    Employee bufferEmployee;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            if(!(menu_ModifyEmployee(&modifyOption)))
            {
                switch(modifyOption)
                {
                case 1:
                    if(!(controller_ListEmployee(pArrayListEmployee)))
                    {
                        printf("\n >>>>> EMPLEADOS LISTADOS CON EXITO <<<<<\n");
                    }
                    break;
                case 2:
                    if(!(utn_getInt("Ingrese ID empleado: ", "Error, reintentos", &bufferId, 3))
                            && !(employee_findById(pArrayListEmployee, bufferId, &bufferIndex)))
                    {
                        pBufferAux = (Employee*)ll_get(pArrayListEmployee, bufferIndex);
                        if(pBufferAux != NULL)
                        {
                            printf("\n >>>>> EMPLEADOS ENCONTRADO: %s <<<<<\n", employee_getNombre(pBufferAux));
                            output = 1;
                        }
                    }
                    break;
                case 3:
                    if(!(utn_getString("Ingrese nuevo nombre: ", "Error, reintentos", bufferEmployee.nombre, SIZE_NAME, 3))
                            && !(employee_setNombre(pBufferAux, bufferEmployee.nombre)))
                    {
                        output = 0;
                    }
                    break;
                case 4:
                    if(!(utn_getInt("Ingrese nuevas horas: ", "Error, reintentos", &bufferEmployee.horasTrabajadas, 3))
                                && !(employee_setHorasTrabajadas(pBufferAux, bufferEmployee.horasTrabajadas)))
                    {
                        output = 0;
                    }
                    break;
                case 5:
                    if(!(utn_getFloat("Ingrese nuevo sueldo: ", "Error, reintentos", &bufferEmployee.sueldo, 3))
                                && !(employee_setSueldo(pBufferAux, bufferEmployee.sueldo)))
                    {
                        output = 0;
                    }
                    break;
                case 6:
                    printf("\n >>>>> VOLVLIENDO AL MENU PRINCIPAL <<<<<\n");
                    break;
                default:
                    printf("\n >>>>> OPCION INVALIDA <<<<<\n");
                }
            }

        }while(modifyOption != 6);
    }
    return output;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int output = -1;
    int removeOption;
    int bufferId;
    int bufferBaja;
    int bufferIndex;
    int bufferListIndex;
    Employee* pBufferAux;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            if(!(menu_RemoveEmployee(&removeOption)))
            {
                switch(removeOption)
                {
                case 1:
                    if(!(controller_ListEmployee(pArrayListEmployee)))
                    {
                        printf("\n >>>>> EMPLEADOS LISTADOS CON EXITO <<<<<\n");
                    }
                    break;
                case 2:
                    if(!(utn_getInt("Ingrese ID empleado: ", "Error, reintentos", &bufferId, 3))
                            && !(employee_findById(pArrayListEmployee, bufferId, &bufferIndex)))
                    {
                        pBufferAux = (Employee*)ll_get(pArrayListEmployee, bufferIndex);
                        if(pBufferAux != NULL)
                        {
                            printf("\nEMPLEADO A DAR DE BAJA: %s (CONFIRMAR BAJA CON OPCION 3)\n", employee_getNombre(pBufferAux));
                            output = 1;
                        }
                    }
                    else
                    {
                        printf("\n >>>>> EMPLEADOS NO ENCONTRADO (VUELVA A LISTAR EMPLEADOS) <<<<<\n");
                    }
                    break;
                case 3:
                    if(!(utn_getInt("\t(0). CONFIRMAR BAJAR\n\t(1). DESCARTAR BAJA ------> ", "Error, reintentos", &bufferBaja, 3))
                            && bufferBaja == 0)
                    {
                        bufferListIndex = ll_indexOf(pArrayListEmployee, pBufferAux);
                        if(bufferListIndex > 0 && !(employee_delete(pBufferAux)) && !(ll_remove(pArrayListEmployee, bufferListIndex)))
                        {
                            output = 0;
                        }
                    }
                    break;
                case 4:
                    printf("\n >>>>> VOLVLIENDO AL MENU PRINCIPAL <<<<<\n");
                    break;
                default:
                    printf("\n >>>>> OPCION INVALIDA <<<<<\n");
                }
            }
        }
        while(removeOption != 4);

    }
    return output;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int output = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        printColumn();
        for(int x = 0; x < len; x++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee, x);
            if(aux != NULL)
            {
                printf("%5d |%22s| %20d| %20.2f|\n", employee_getId(aux), employee_getNombre(aux),
                                                employee_getHorasTrabajadas(aux), employee_getSueldo(aux));
            }
            output = 0;
        }
    }
    return output;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int output = -1;
    int bufferOrder;
    int bufferSortMenu;
    if(pArrayListEmployee != NULL)
    {
        do
        {
            if(!(menu_SortEmployee(&bufferSortMenu)))
            {
                switch(bufferSortMenu)
                {
                case 1:
                    if(!(utn_getIntConMinMax("(0). ORDENAR DE FORMA DESCENDENTE\n(1). ORDENAR DE FORMA ASCENDENTE -----> "
                            , "Error, reintentos", &bufferOrder, 0, 1, 3))
                            && !(ll_sort(pArrayListEmployee, employee_sortEmployeesById, bufferOrder)))
                    {
                        output = 0;
                    }
                    break;
                case 2:
                    if(!(utn_getIntConMinMax("(0). ORDENAR DE FORMA DESCENDENTE\n(1). ORDENAR DE FORMA ASCENDENTE -----> "
                            , "Error, reintentos", &bufferOrder, 0, 1, 3))
                            && !(ll_sort(pArrayListEmployee, employee_sortEmployeesByName, bufferOrder)))
                    {
                        output = 0;
                    }
                    break;
                case 3:
                    if(!(utn_getIntConMinMax("(0). ORDENAR DE FORMA DESCENDENTE\n(1). ORDENAR DE FORMA ASCENDENTE -----> "
                            , "Error, reintentos", &bufferOrder, 0, 1, 3))
                            && !(ll_sort(pArrayListEmployee, employee_sortEmployeesBySueldo, bufferOrder)))
                    {
                        output = 0;
                    }
                    break;
                case 4:
                    if(!(utn_getIntConMinMax("(0). ORDENAR DE FORMA DESCENDENTE\n(1). ORDENAR DE FORMA ASCENDENTE -----> "
                            , "Error, reintentos", &bufferOrder, 0, 1, 3))
                            && !(ll_sort(pArrayListEmployee, employee_sortEmployeesByHorasTrabajadas, bufferOrder)))
                    {
                        output = 0;
                    }
                    break;
                case 5:
                    printf("\n >>>>> VOLVLIENDO AL MENU PRINCIPAL <<<<<\n");
                    break;
                default:
                    printf("\n >>>>> OPCION INVALIDA <<<<<\n");
                }
            }
        }while (bufferSortMenu !=5);
            output = 0;
    }
    return output;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int output = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* out;
        out = fopen(path, "w");
        if(out != NULL)
        {
            if(!(parser_EmployeeToText(out, pArrayListEmployee)))
            {
                output = 0;
            }
            fclose(out);
        }
    }
    return output;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int output = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* out;
        out = fopen(path, "wb");
        if(out != NULL)
        {
            if(!(parser_EmployeeToBinary(out, pArrayListEmployee)))
            {
                output = 0;
            }
            fclose(out);
        }
    }
    return output;
}

