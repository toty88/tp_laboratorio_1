#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ArrayEmployees.h"

/**
 * @fn int hardcodeArrayEmployees(Employee*)
 * @brief Funcion que caga 5 alumnos por defecto al comenzar el programa
 *
 * @param pArray: El array de tipo Empleado
 * @return (-1) Error (0) todo OK
 */
int hardcodeArrayEmployees(Employee *pArray) {
    int output = -1;
    int bufferID[5] = { 100, 101, 102, 103, 104 };
    char bufferName[5][SIZE_NAMES] = { "MALCOM", "ANGUS", "BRIAN", "RICARDO",
            "BRUCE" };
    char bufferLastName[5][SIZE_NAMES] = { "YOUNG", "DICIKINSON", "JHONSON", "IORIO",
            "DICIKINSON" };
    float bufferSalary[5] = { 800, 900, 1000, 2300, 5100 };
    int bufferSector[5] = { 1, 2, 3, 4, 5 };

    if (pArray != NULL) {
        for (int x = 0; x < 5; x++) {
            strncpy(pArray[x].name, bufferName[x], SIZE_NAMES);
            strncpy(pArray[x].lastName, bufferLastName[x], SIZE_NAMES);
            pArray[x].sector = bufferSector[x];
            pArray[x].salary = bufferSalary[x];
            pArray[x].id = bufferID[x];
            pArray[x].isEmpty = FALSE;
        }
        output = 0;
    }
    return output;
}

/**
 * @fn int initEmployees(Employee*, int)
 * @brief Funcion que inicializa cada elemento del array en su campo isEmpty
 *
 * @param pArray: El array de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @return (-1) Error (0) todo OK
 */
int initEmployees(Employee *pArray, int len) {
    int output = -1;
    if (pArray != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            pArray[x].isEmpty = TRUE;
        }
        output = 0;
    }
    return output;
}

/**
 * @fn int findEmployeeById(Employee*, int, int, int*)
 * @brief Funcion que encuentra un elemento del array en base al ID y devuelve su indice
 *
 * @param pArray: El array de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @param id: El id a comparar con cada campo ID de los elementos del array
 * @param indexPosition: El puntero a int donde guardar el indice encontrado
 * @return (-1) Error (0) todo OK
 */
int findEmployeeById(Employee *pArray, int len, int id, int *indexPosition) {

    int output = -1;
    if (pArray != NULL && indexPosition != NULL && len > 0 && id > 0) {
        for (int x = 0; x < len; x++) {
            if (pArray[x].id == id && pArray[x].isEmpty == FALSE) {
                *indexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int findFirstFreePosition(Employee*, int, int*)
 * @brief Funcion que encuentra el primer indice vacio de acuerdo al campo
 *        isEmpty
 *
 * @param pArray: El array de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @param freeIndexPosition: El puntero a int donde guardar el indice
 * @return (-1) Error (0) todo OK
 */
int findFirstFreePosition(Employee *pArray, int len, int *freeIndexPosition) {
    int output = -1;
    if (pArray != NULL && freeIndexPosition != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            if (pArray[x].isEmpty == TRUE) {
                *freeIndexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int getEmployeeID(int*)
 * @brief Funcion que calcula de forma autoincremental un ID
 *
 * @param employeeID: El punto a int donde guardar el ID
 * @return (-1) Error (0) todo OK
 */
static int getEmployeeID(int *employeeID) {

    int output = -1;
    static int id = 105;
    if (employeeID != NULL) {
        *employeeID = id++;
        output = 0;
    }
    return output;
}

/**
 * @fn int createEmployee(Employee*, int)
 * @brief Funcion que crea un elemento de tipo Empleado
 *
 * @param pArray: El array de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @return (-1) Error (0) todo OK
 */
int createEmployee(Employee *pArray, int len) {

    int output = -1;
    Employee bufferEmployee;
    int bufferFreeIndexPosition;

    if (pArray != NULL && len > 0
            && !(findFirstFreePosition(pArray, len,
                    &bufferFreeIndexPosition))) {
        if (!(utn_getString("(a). Ingrese nombre: ", "Error, reintentos", bufferEmployee.name, SIZE_NAMES, 3))
                && !(utn_getString("(b). Ingrese apellido: ", "Error, reintentos", bufferEmployee.lastName, SIZE_NAMES, 3))
                && !(utn_getFloatConMinMax("(c). Ingrese salario entre [10.000:90.000]: ", "Error, reintentos",
                        &bufferEmployee.salary, 10000.0, 90000.0, 3))
                && !(utn_getIntConMinMax("(d). Ingrese sector entre [01:20]: ", "Error, reintentos",
                        &bufferEmployee.sector, 1, 20, 3))
                && !(getEmployeeID(&bufferEmployee.id))
                && !(addEmployees(pArray, len, bufferEmployee.id,
                        bufferEmployee.name, bufferEmployee.lastName,
                        bufferEmployee.salary, bufferEmployee.sector,
                        bufferFreeIndexPosition))) {

            output = 0;
        }
    }
    return output;
}

/**
 * @fn int addEmployees(Employee*, int, int, char*, char*, float, int, int)
 * @brief Funcion que da de alta un elemento creado de tipo Empleado
 *
 * @param pArray: El array de tipo Empleado
 * @param len: La cantidad de elementos de tipo Empleado
 * @param id: El id del empleado
 * @param name: el nombre del empleado
 * @param lastName: el apellido del empleado
 * @param salary: el salario del empleado
 * @param sector: el sector del empleado
 * @param freeIndexPosition: el indice donde estara almacenado el empleado
 * @return (-1) Error (0) todo OK
 */
int addEmployees(Employee *pArray, int len, int id, char *name, char *lastName, float salary, int sector, int freeIndexPosition) {

    int output = -1;

    if (pArray != NULL && name != NULL && lastName != NULL && len > 0
            && id > 0 && salary > 0 && sector > 0 && freeIndexPosition >= 0) {

        pArray[freeIndexPosition].sector = sector;
        pArray[freeIndexPosition].salary = salary;
        pArray[freeIndexPosition].id = id;
        strcpy(pArray[freeIndexPosition].name, name);
        strcpy(pArray[freeIndexPosition].lastName, lastName);
        pArray[freeIndexPosition].isEmpty = FALSE;
        output = 0;
    }
    return output;
}

/**
 * @fn int modifyEmployees(Employee*, int)
 * @brief Funcion que brinda opciones de moficiacion de un empleado
 *
 * @param pArray: El array de tipo Empleado
 * @param len: La cantidad de elementos de tipo Empleado
 * @return (-1) Error (0) todo OK
 */
int modifyEmployees(Employee *pArray, int len) {
    int output = -1;
    int opcionMenuModificaciones;
    int flag;
    int bufferID;
    int bufferIndex;
    Employee bufferEmployee;

    if (pArray != NULL && len > 0) {
        do {
            if (!(modifyEmployeeMenu(&opcionMenuModificaciones))) {
                switch (opcionMenuModificaciones) {
                case 1:
                    printColumn();
                    if (!printEmployees(pArray, len)) {
                        output = 1;
                    }
                    break;
                case 2:
                    if (!(utn_getInt("\nIngrese ID del empleado a modificar: ",
                            "Error, reintentos", &bufferID, 3))) {
                        if (findEmployeeById(pArray, len, bufferID,
                                &bufferIndex)) {
                            printf(
                                    "ID INVALIDO, VUELVA A LISTAR EMPLEADOS O SALGA\n");
                        } else {
                            flag = 1;
                        }
                        output = 1;
                    }
                    break;
                case 3:
                    if (flag == 1) {
                        if (!(utn_getString("\n(a). Ingrese nuevo nombre: ",
                                "Error, reintentos", bufferEmployee.name,
                                SIZE_NAMES, 3))) {
                            strncpy(pArray[bufferIndex].name,
                                    bufferEmployee.name, SIZE_NAMES);
                            output = 0;
                        }
                    } else {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 4:
                    if (flag == 1) {
                        if (!(utn_getString("(b). Ingrese nuevo apellido: ",
                                "Error, reintentos", bufferEmployee.lastName,
                                SIZE_NAMES, 3))) {
                            strncpy(pArray[bufferIndex].lastName,
                                    bufferEmployee.lastName, SIZE_NAMES);
                            output = 0;
                        }
                    } else {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 5:
                    if (flag == 1) {
                        if (!(utn_getFloatConMinMax("(c). Ingrese nuevo salario entre [10000:50000]: ",
                                "Error, reintentos", &bufferEmployee.salary, 10000.0, 50000.0, 3))) {
                            pArray[bufferIndex].salary =
                                    bufferEmployee.salary;
                            output = 0;
                        }
                    } else {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 6:
                    if (flag == 1) {
                        if (!!(utn_getIntConMinMax("(d). Ingrese nuevo sector entre [01:20]: ",
                                "Error, reintentos", &bufferEmployee.sector, 1, 20, 3))) {
                            pArray[bufferIndex].sector =
                                    bufferEmployee.sector;
                            output = 0;
                        }
                    } else {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 7:
                    printf("SALIENDO AL MENU PRINCIPAL\n");
                    break;
                default:
                    printf("ERROR, OPCION INVALIDA\n");
                }
            }
            printf("\nPresione una tecla para continuar");
            __fpurge(stdin);
            getchar();
            system("clear");
        } while (opcionMenuModificaciones != 7);
    }
    return output;
}

/**
 * @fn int removeEmployee(Employee*, int)
 * @brief Funcion que da de baja un elemento de tipo Empleado
 *
 * @param pArray: Array de elementos de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @return (-1) Error (0) todo OK
 */
int removeEmployee(Employee *pArray, int len) {
    int output = -1;
    int opcionMenuBaja;
    int confirmaEliminacion;
    int bufferID;
    int bufferIndex;

    if (pArray != NULL && len > 0) {
        do {
            if (!(removeEmployeeMenu(&opcionMenuBaja))) {
                switch (opcionMenuBaja) {
                case 1:
                    printColumn();
                    if (printEmployees(pArray, len)) {
                        printf("ERROR AL LISTAR EMPLEADOS\n");
                        opcionMenuBaja = 7;
                    }
                    break;
                case 2:
                    if (!(utn_getInt("\nIngrese ID del empleado a eliminar: ",
                            "Error, reintentos", &bufferID, 3))) {
                        if (findEmployeeById(pArray, len, bufferID,
                                &bufferIndex)) {
                            printf(
                                    "ID INVALIDO, VUELVA A LISTAR EMPLEADOS O SALGA\n");
                            output = 1;
                        } else {
                            printf("CONFIRMAR BAJA %s %s\n",
                                    pArray[bufferIndex].name,
                                    pArray[bufferIndex].lastName);
                            if (!utn_getInt("(1). CONFIRMAR\n(2). CANCELAR: -------------> ",
                                    "Error, reintentos", &confirmaEliminacion,
                                    3)) {
                                if (confirmaEliminacion == 1) {
                                    pArray[bufferIndex].isEmpty = TRUE;
                                    output = 0;
                                } else if (confirmaEliminacion == 2) {
                                    output = 1;

                                } else {
                                    printf("OPCION INVALIDA\n");
                                }
                            }
                        }
                    }
                    break;
                case 3:
                    printf("SALIENDO AL MENU PRINCIPAL\n");
                    break;
                default:
                    printf("ERROR, OPCION INVALIDA\n");
                }
            }
            printf("\nPresione una tecla para continuar");
            __fpurge(stdin);
            getchar();
            system("clear");
        } while (opcionMenuBaja != 3);
    }
    return output;
}

/**
 * @fn void printOneEmployee(Employee)
 * @brief Funcion que imprime un solo elemento de tipo Empleado
 *
 * @param employee: El elemento de tipo Empleado
 */
int printOneEmployee(Employee employee) {
    int output = -1;
    if(employee.isEmpty == FALSE){
        printf("# %d %20s %20s %10d %16.2f\n", employee.id, employee.lastName,
                employee.name, employee.sector, employee.salary);
        output = 0;
    }
    return output;
}

/**
 * @fn int printEmployees(Employee*, int)
 * @brief Funcion que imprime todos los empleados que esten activos
 *
 * @param pArray: Array de elementos de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @return (-1) Error (0) todo OK
 */
int printEmployees(Employee *pArray, int len) {
    int output = -1;
    if (pArray != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            printOneEmployee(pArray[x]);
        }
        output = 0;
    }
    return output;
}

/**
 * @fn int getEmployeesAverageSalary(Employee*, int, float*, float*)
 * @brief Funcion que calcula la suma total de los salarios y el salario promedio
 *
 * @param pArray: Array de elementos de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @param pAverageSalary: El puntero a float donde se guardara el salario promedio calculado
 * @param pTotalSalarios: EL puntero a float donde se guardara la suma total de los salarios
 * @return (-1) Error (0) todo OK
 */
int getEmployeesAverageSalary(Employee *pArray, int len, float *pAverageSalary, float *pTotalSalarios) {

    int output = -1;
    float bufferTotalSalary = 0;
    int bufferAmountOfActiveEmployees = 0;
    if (pArray != NULL && pAverageSalary != NULL && pTotalSalarios != NULL
            && len > 0) {

        for (int x = 0; x < len; x++) {
            if (pArray[x].isEmpty == FALSE) {
                bufferTotalSalary += pArray[x].salary;
                bufferAmountOfActiveEmployees++;
            }
        }
        if (bufferAmountOfActiveEmployees > 0) {
            *pTotalSalarios = bufferTotalSalary;
            *pAverageSalary = bufferTotalSalary / bufferAmountOfActiveEmployees;
            output = 0;
        }else{
            *pTotalSalarios = 0;
            *pAverageSalary = 0;
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int getEmployeesAboveAverageSalary(Employee*, int, int)
 * @brief Funcion que imprime los empleados que tengan salarios por encima del salario promedio
 *
 * @param pArray: Array de elementos de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @param averageSalary: El salario promedio
 * @return (-1) Error (0) todo OK
 */
int getEmployeesAboveAverageSalary(Employee *pArray, int len, int averageSalary) {

    int output = -1;
    if (pArray != NULL && len > 0 && averageSalary > 0) {
        printColumnAboveAverageSalary();
        for (int x = 0; x < len; x++) {
            if (pArray[x].isEmpty == FALSE && pArray[x].salary > averageSalary) {
                printOneEmployee(pArray[x]);
            }
        }
        output = 0;
    }
    return output;

}

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Funcion que ordena los empleados por apellido y sector
 *
 * @param pArray: Array de elementos de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @param order (1) orden ASCENDENTE (2) orden DESCENDENTE
 * @return (-1) Error (0) todo OK
 */
int sortEmployees(Employee *pArray, int len, int order) {
    int output = -1;
    int flag = 1;
    Employee bufferEmployee;
    if (pArray != NULL && len > 0 && (order == 1 || order == 2)) {
        do {
            flag = 0;
            for (int x = 0; x < (len-1); x++){

                if( ((order == 1) &&
                    (strncmp(pArray[x].lastName, pArray[x+1].lastName, SIZE_NAMES) > 0 ||
                    (strncmp(pArray[x].lastName, pArray[x+1].lastName, SIZE_NAMES) == 0 &&
                    pArray[x].sector > pArray[x+1].sector)) )
                    ||
                    ((order == 2) &&
                    (strncmp(pArray[x].lastName, pArray[x+1].lastName, SIZE_NAMES) < 0 ||
                    (strncmp(pArray[x].lastName, pArray[x+1].lastName, SIZE_NAMES) == 0 &&
                    pArray[x].sector < pArray[x+1].sector)) )){

                    bufferEmployee = pArray[x];
                    pArray[x] = pArray[x + 1];
                    pArray[x + 1] = bufferEmployee;
                    flag = 1;
                    output = 0;
                }
            }
        } while (flag);
    }

    return output;
}

/**
 * @fn int reportsEmployees(Employee*, int)
 * @brief Funcion que brinda opciones para listar&ordenar empleados y calcular salario total&promedio
 *
 * @param pArray: Array de elementos de tipo Empleado
 * @param len: La cantidad de elementos del array de tipo Empleado
 * @return (1) Error (0) todo OK
 */
int reportsEmployees(Employee *pArray, int len) {

    int output = -1;
    int order;
    float bufferAverageSalary;
    float bufferSalarySum;
    int opcionMenuInformes;

    if (pArray != NULL && len > 0) {
        do {
            __fpurge(stdin);
            if (!(reportsEmployeeMenu(&opcionMenuInformes))) {
                switch (opcionMenuInformes) {
                case 1:
                    printColumn();
                    if (printEmployees(pArray, len)) {
                        printf("Error al listar empleados\n");
                    }
                    break;

                case 2:
                    if (!(utn_getInt(
                            "\n(1). ORDENAR POR APELLIDO Y SECTOR DE FORMA ASCENDENTE"
                            "\n(2). ORDENAR POR APELLIDO Y SECTOR DE FORMA DESCENDENTE: ",
                            "ERROR, REINTENTOS", &order, 3)) && !(sortEmployees(pArray, len, order)))
                    {
                        if(order == 1){
                            printColumnSortedAs();
                        }else{
                            printColumnSortedDes();
                        }
                        printEmployees(pArray, len);
                        output = 0;
                    }
                    break;
                case 3:
                    if (!(getEmployeesAverageSalary(pArray, len,
                            &bufferAverageSalary, &bufferSalarySum))) {
                        printf(
                                "\n(#). SALARIO TOTAL DE EMPLEADOS: \t$%.2f\n(#). SALARIO PROMEDIO DE EMPLEADOS: \t$%.2f\n",
                                bufferSalarySum, bufferAverageSalary);
                        if (!(getEmployeesAboveAverageSalary(pArray, len, bufferAverageSalary))) {
                            output = 0;
                        }
                    } else {
                        printf(
                                "HUBO UN ERROR AL CALCULAR SALARIOS & PROMEDIOS\n");
                    }
                    break;
                case 4:
                    printf("SALIENDO AL MENU PRINCIPAL\n");
                    break;
                default:
                    printf("ERROR, OPCION INVALIDA\n");
                }
            }
            printf("\nPresione una tecla para continuar");
            __fpurge(stdin);
            getchar();
            system("clear");
        } while (opcionMenuInformes != 4);
    }
    return output;
}

