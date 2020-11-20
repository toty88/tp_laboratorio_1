#include"Employee.h"


/**
 * @fn Employee employee_new*(void)
 * @brief funcion que a asigna y devuelve un puntero tipo Empleado
 *
 * @return el puntero a Empleado o NULL
 */
Employee* employee_new(void)
{
    return (Employee*)malloc(sizeof(Employee));
}

/**
 * @fn Employee employee_newParametrosTXT*(char*, char*, char*, char*)
 * @brief funcion que crea un empleado con parametros de tipo char*
 *
 * @param idStr el id
 * @param nombreStr el nombre
 * @param horasTrabajadasStr las horas trabajadas
 * @param sueldStr el sueldo
 * @return (1) Error (0) Todo OK
 */
Employee* employee_newParametrosTXT(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldStr)
{
    Employee* this = employee_new();
    if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldStr != NULL)
    {
        if(!(employee_setIdTXT(this, idStr))
            && !(employee_setNombre(this, nombreStr))
            && !(employee_setHorasTrabajadasTXT(this, horasTrabajadasStr))
            && !(employee_setSueldoTXT(this, sueldStr)))
        {
            return this;
        }
    }
    return NULL;
}

/**
 * @fn Employee employee_newParam*(int, char*, int, float)
 * @brief funcion que crea un empleado con parametros
 *
 * @param idS el id
 * @param nombre el nombre
 * @param horasTrabajadas las horas trabajadas
 * @param sueldo el sueldo
 * @return (1) Error (0) Todo OK
 */
Employee* employee_newParam(int id, char* nombre, int horasTrabajadas, float sueldo)
{
    Employee* this = employee_new();
    if(this != NULL)
    {
        if(!(employee_setId(this, id))
            && !(employee_setNombre(this, nombre))
            && !(employee_setHorasTrabajadas(this, horasTrabajadas))
            && !(employee_setSueldo(this, sueldo)))
        {
            return this;
        }
    }
    return NULL;
}

/**
 * @fn int employee_delete(Employee*)
 * @brief funcion que elimina un empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @return  (1) Error (0) Todo OK
 */
int employee_delete(Employee* this)
{
    int output = -1;
    if(this != NULL)
    {
        free(this);
        output = 0;
    }
    return output;
}

/**
 * @fn int employee_sortEmployeesById(void*, void*)
 * @brief funcion criterio que devuelve una comparacion entre dos IDs
 *
 * @param pBuffer1 elemento1 que se casteara a tipo Employee*
 * @param pBuffer2 elemento2 que se casteara a tipo Employee*
 * @return (-1) Error (0) Todo OK
 */
int employee_sortEmployeesById(void* pBuffer1, void* pBuffer2)
{
    int output = -1;
    if(pBuffer1 != NULL && pBuffer2 != NULL)
    {
        Employee* e1;
        Employee* e2;
        e1 = (Employee*) pBuffer1;
        e2 = (Employee*) pBuffer2;
        if(employee_getId(e1) > employee_getId(e2))
        {
            output = 1;
        }
        else if(employee_getId(e1) < employee_getId(e2))
        {
            output = -1;
        }
        else
        {
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int employee_sortEmployeesById(void*, void*)
 * @brief funcion criterio que devuelve una comparacion entre dos nombres
 *
 * @param pBuffer1 elemento1 que se casteara a tipo Employee*
 * @param pBuffer2 elemento2 que se casteara a tipo Employee*
 * @return (-1) Error (0) Todo OK
 */
int employee_sortEmployeesByName(void* pBuffer1, void* pBuffer2)
{
    int output = -1;

    if(pBuffer1 != NULL && pBuffer2 != NULL)
    {
        Employee* e1;
        Employee* e2;
        e1 = (Employee*) pBuffer1;
        e2 = (Employee*) pBuffer2;

        output = strncmp(employee_getNombre(e1), employee_getNombre(e2), SIZE_NAME);
    }
    return output;
}

/**
 * @fn int employee_sortEmployeesById(void*, void*)
 * @brief funcion criterio que devuelve una comparacion entre dos horas Trabajadas
 *
 * @param pBuffer1 elemento1 que se casteara a tipo Employee*
 * @param pBuffer2 elemento2 que se casteara a tipo Employee*
 * @return (-1) Error (0) Todo OK
 */
int employee_sortEmployeesByHorasTrabajadas(void* pBuffer1, void* pBuffer2)
{
    int output = -1;
    if(pBuffer1 != NULL && pBuffer2 != NULL)
    {
        Employee* e1;
        Employee* e2;
        e1 = (Employee*) pBuffer1;
        e2 = (Employee*) pBuffer2;
        if(employee_getHorasTrabajadas(e1) > employee_getHorasTrabajadas(e2))
        {
            output = 1;
        }
        else if(employee_getHorasTrabajadas(e1) < employee_getHorasTrabajadas(e2))
        {
            output = -1;
        }
        else
        {
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int employee_sortEmployeesById(void*, void*)
 * @brief funcion criterio que devuelve una comparacion entre dos Sueldos
 *
 * @param pBuffer1 elemento1 que se casteara a tipo Employee*
 * @param pBuffer2 elemento2 que se casteara a tipo Employee*
 * @return (-1) Error (0) Todo OK
 */
int employee_sortEmployeesBySueldo(void* pBuffer1, void* pBuffer2)
{
    int output = -1;
    if(pBuffer1 != NULL && pBuffer2 != NULL)
    {
        Employee* e1;
        Employee* e2;
        e1 = (Employee*) pBuffer1;
        e2 = (Employee*) pBuffer2;
        if(employee_getSueldo(e1) > employee_getSueldo(e2))
        {
            output = 1;
        }
        else if(employee_getSueldo(e1) < employee_getSueldo(e2))
        {
            output = -1;
        }
        else
        {
            output = 0;
        }
    }
    return output;
}

/* ################### GETTERS ##################### */

/**
 * @fn int employee_getId(Employee*)
 * @brief funcion que devuelve un id por valor de retorno
 *
 * @param this el elemento de tipo puntero a empleado
 * @return el id
 */
int employee_getId(Employee* this)
{
    return this->id;
}

/**
 * @fn int employee_getId(Employee*)
 * @brief funcion que devuelve un nombre por valor de retorno
 *
 * @param this el elemento de tipo puntero a empleado
 * @return el nombre
 */
char* employee_getNombre(Employee* this)
{
    return this->nombre;
}

/**
 * @fn int employee_getId(Employee*)
 * @brief funcion que devuelve las horas trabajadas por valor de retorno
 *
 * @param this el elemento de tipo puntero a empleado
 * @return las horas trabajadas
 */
int employee_getHorasTrabajadas(Employee* this)
{
    return this->horasTrabajadas;
}

/**
 * @fn int employee_getId(Employee*)
 * @brief funcion que devuelve un sueldo por valor de retorno
 *
 * @param this el elemento de tipo puntero a empleado
 * @return el sueldo
 */
float employee_getSueldo(Employee* this)
{
    return this->sueldo;
}

/* ################################################ */

/* ####### SETTERS Y VALIDACIONES COMO TEXTO #######*/

/**
 * @fn int employee_setIdTXT(Employee*, char*)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param id el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setIdTXT(Employee* this, char* id)
{
    int output = -1;
    int bufferID;
    if(this != NULL && id != NULL &&  employee_isValidIdTXT(id))
    {
        bufferID = atoi(id);
        this->id = bufferID;
        output = 0;
    }
     return output;
}

int  employee_isValidIdTXT(char* id)
{
    int output = 0;
    int bufferID;
    if(id !=NULL && utn_isIntNumber(id))
    {
        bufferID = atoi(id);
        if(bufferID > 0)
        {
            output = 1;
        }
    }
    return output;
}

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param nombre el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setNombre(Employee* this, char* nombre)
{
    int output = -1;
    if(this != NULL && nombre != NULL &&  employee_isValidNombre(nombre))
    {
        strncpy(this->nombre,nombre,(int)sizeof(this->nombre));
        output = 0;
    }
    return output;
}

/**
 * @fn int employee_isValidNombre(char*)
 * @brief funcion que valida un nombre
 *
 * @param nombre el nombre a validar
 * @return (-1) Error (0) Todo OK
 */
int  employee_isValidNombre(char* nombre)
{
    int output = 1;
    if(nombre !=NULL){
        for(int x = 0; nombre[x] !='\0'; x++){
            if((nombre[x] < 'A' || nombre[x] > 'z') && (nombre[x] > 'Z' || nombre[x] < 'a') && nombre[x] != ' ' && nombre[x] != '-'){
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int employee_setHorasTrabajadasTXT(Employee*, char*)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param horasTrabajadas el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setHorasTrabajadasTXT(Employee* this, char* horasTrabajadas)
{
    int output = -1;
    int bufferHoras;
    if(this != NULL  &&  horasTrabajadas != NULL && employee_isValidHorasTrabajadasTXT(horasTrabajadas))
    {
        bufferHoras = atoi(horasTrabajadas);
        this->horasTrabajadas = bufferHoras;
        output = 0;
    }
     return output;
}

/**
 * @fn int employee_isValidHorasTrabajadasTXT(char*)
 * @brief funcion que valida las horas trabajadas
 *
 * @param horasTrabajadas las horas trabajadas a validar
 * @return (-1) Error (0) Todo OK
 */
int  employee_isValidHorasTrabajadasTXT(char* horasTrabajadas)
{
    int output = 0;
    int bufferHoras;
    if(horasTrabajadas !=NULL && utn_isIntNumber(horasTrabajadas))
    {
        bufferHoras = atoi(horasTrabajadas);
        if(bufferHoras > 0)
        {
            output = 1;
        }
    }
    return output;
}

/**
 * @fn int employee_setSueldoTXT(Employee*, char*)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param sueldo el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setSueldoTXT(Employee* this, char* sueldo)
{
    int output = -1;
    float bufferSueldo;
    if(this != NULL  &&  sueldo != NULL && employee_isValidSueldoTXT(sueldo))
    {
        bufferSueldo = atof(sueldo);
        this->sueldo = bufferSueldo;
        output = 0;
    }
     return output;
}

/**
 * @fn int employee_isValidSueldoTXT(char*)
 * @brief funcion que valida un sueldo
 *
 * @param sueldo el sueldo a validar
 * @return (-1) Error (0) Todo OK
 */
int  employee_isValidSueldoTXT(char* sueldo)
{
    int output = 0;
    float bufferSueldo;
    if(sueldo !=NULL && utn_isFloatNumber(sueldo))
    {
        bufferSueldo = atof(sueldo);
        if(bufferSueldo > 0)
        {
            output = 1;
        }
    }
    return output;
}

/* ################################################ */

/* ####### SETTERS Y VALIDACIONES COMO PRIMITIVOS #######*/

/**
 * @fn int employee_setId(Employee*, int)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param id el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setId(Employee* this, int id)
{
    int output = -1;
    if(this != NULL && employee_isValidId(id))
    {
        this->id = id;
        output = 0;
    }
    return output;
}

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param horasTrabajadas el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int output = -1;
    if(this != NULL && employee_isValidHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas = horasTrabajadas;
        output = 0;
    }
    return output;
}

/**
 * @fn int employee_setSueldo(Employee*, float)
 * @brief funcion que setea un valor a un elemento de tipo puntero a empleado
 *
 * @param this el elemento de tipo puntero a empleado
 * @param sueldo el valor a setear
 * @return (-1) Error (0) Todo OK
 */
int employee_setSueldo(Employee* this, float sueldo)
{
    int output = -1;
    if(this != NULL && employee_isValidSueldo(sueldo))
    {
        this->sueldo = sueldo;
        output = 0;
    }
    return output;
}

/**
 * @fn int employee_isValidId(int)
 * @brief funcion que valida un ID
 *
 * @param id el ID a validar
 * @return (-1) Error (0) Todo OK
 */
int employee_isValidId(int id)
{
    int output = 0;
    if(id > 0)
    {
        output = 1;
    }
    return output;
}

/**
 * @fn int employee_isValidHorasTrabajadas(int)
 * @brief funcion que valida las horas trabajadas
 *
 * @param horasTrabajadas las horas trabajadas a validar
 * @return (-1) Error (0) Todo OK
 */
int employee_isValidHorasTrabajadas(int horasTrabajadas)
{
    int output = 0;
    if(horasTrabajadas > 0)
    {
        output = 1;
    }
    return output;
}

/**
 * @fn int employee_isValidSueldo(float)
 * @brief funcion que valida un sueldo
 *
 * @param sueldo el sueldo a validar
 * @return (-1) Error (0) Todo OK
 */
int employee_isValidSueldo(float sueldo)
{
    int output = 0;
    if(sueldo > 0)
    {
        output = 1;
    }
    return output;
}

/* ###################################################### */
