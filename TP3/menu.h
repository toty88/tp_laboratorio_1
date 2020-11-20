#ifndef MENU_H_
#define MENU_H_

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

/* ######################## MENUES GENERALES ############################*/

int menu_Main(int*);
int menu_ModifyEmployee(int*);
int menu_RemoveEmployee(int*);
int menu_SortEmployee(int*);

/* ######################## HEADERS LISTAS #############################*/

void printColumn(void);



#endif /* MENU_H_ */
