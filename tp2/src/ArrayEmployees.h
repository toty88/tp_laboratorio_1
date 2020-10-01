#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

//#include<stdio.h>
#include"menu.h"
#include"utn.h"
#define SIZE_ARRAY_EMPLOYEES 1000
#define FALSE 0
#define TRUE 1
#define SIZE_NAMES 51
typedef struct{

	int id;
	char name[SIZE_NAMES];
	char lastName[SIZE_NAMES];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int initEmployees(Employee*, int);
int hardcodeArrayEmployees(Employee*);
int findFirstFreePosition(Employee*, int, int*);
int findEmployeeById(Employee*, int, int, int*);
int createEmployee(Employee*, int);
int addEmployees(Employee*, int, int, char*, char*, float, int, int);
int printOneEmployee(Employee);
int printEmployees(Employee*, int);
int modifyEmployees(Employee*, int);
int reportsEmployees(Employee*, int);
int removeEmployee(Employee*, int);
int sortEmployees(Employee*, int, int);
int getEmployeesAverageSalary(Employee*, int, float*, float*);
int getEmployeesAboveAverageSalary(Employee*, int, int);


#endif /* ARRAYEMPLOYEES_H_ */
