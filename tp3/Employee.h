#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include"utn.h"
#define SIZE_NAME 128

typedef struct
{
    int id;
    char nombre[SIZE_NAME];
    int horasTrabajadas;
    float sueldo;

}Employee;

Employee* employee_new(void);
Employee* employee_newParametrosTXT(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldStr);
Employee* employee_newParam(int id, char* nombre, int horasTrabajadas, float sueldo);
int employee_delete(Employee* this);
int employee_sortEmployeesByName(void*, void*);
int employee_sortEmployeesById(void*, void*);
int employee_sortEmployeesByHorasTrabajadas(void*, void*);
int employee_sortEmployeesBySueldo(void*, void*);

/* ##################### GETTERS ################### */

int     employee_getId(Employee* this);
char*   employee_getNombre(Employee* this);
float   employee_getSueldo(Employee* this);
int     employee_getHorasTrabajadas(Employee* this);

/* ################################################ */

/* ####### SETTERS Y VALIDACIONES COMO TEXTO #######*/

int employee_setIdTXT(Employee* this, char* id);
int employee_setNombre(Employee* this, char* nombre);
int employee_setSueldoTXT(Employee* this, char* sueldo);
int employee_setHorasTrabajadasTXT(Employee* this, char* horasTrabajadas);

int employee_isValidIdTXT(char* id);
int employee_isValidNombre(char* nombre);
int employee_isValidHorasTrabajadasTXT(char* horasTrabajadas);
int employee_isValidSueldoTXT(char* sueldo);

/* ################################################ */

/* ####### SETTERS Y VALIDACIONES COMO PRIMITIVOS #######*/

int employee_setId(Employee* this, int id);
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_setSueldo(Employee* this, float sueldo);

int employee_isValidId(int id);
int employee_isValidHorasTrabajadas(int horasTrabajadas);
int employee_isValidSueldo(float sueldo);

/* ###################################################### */






#endif // employee_H_INCLUDED
