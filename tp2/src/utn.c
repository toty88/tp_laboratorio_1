#include<stdlib.h>
#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<ctype.h>
#include"utn.h"

int myGets(char *cadena, int len) {
	int output = -1;
	char bufferString[4096];
	__fpurge(stdin);
	if (cadena != NULL && len > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
		if (bufferString[0] == '\n') {
			printf("Error, solo ingreso un ENTER\n");
		} else {
			bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			if (strnlen(bufferString, sizeof(bufferString)) <= len) {
				strncpy(cadena, bufferString, len);
				output = 0;
			}
		}
	}
	return output;
}

int utn_getString(char *msg, char *msgError, char *pCadena, int limite, int reintentos) {
	int output = -1;
	if (msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0) {
		do {
			printf("%s", msg);
			if (!(myGets(pCadena, limite))) {
				for(int x = 0; x<limite; x++){
					pCadena[x] = toupper(pCadena[x]);
				}
				output = 0;
			} else {
				reintentos--;
				if (reintentos > 0) {
					printf("%s: %d", msgError, reintentos);
				}
			}
		} while (output != 0 && reintentos > 0);
	}
	return output;
}

int utn_getInt(char *msg, char *msgError, int *pResultado, int reintentos) {
	int output = -1;
	char bufferString[50];
	if (msg != NULL && msgError != NULL && pResultado != NULL
			&& reintentos > 0) {
		do {
			printf("%s", msg);
			if (!(myGets(bufferString, sizeof(bufferString))) && utn_isIntNumber(bufferString)) {
				output = 0;
				*pResultado = atoi(bufferString);
			} else {
				reintentos--;
				if (reintentos > 0) {
					printf("%s: %d", msgError, reintentos);
				}
			}
		} while (output != 0 && reintentos > 0);
	}
	return output;
}

int utn_isIntNumber(char *numberToValidate) {
	int output = 0;
	int contadorSignoNegativo = 0;
	if (numberToValidate != NULL) {
		for (int x = 0; numberToValidate[x] != '\0'; x++) {
			if ((numberToValidate[x] >= '0' && numberToValidate[x] <= '9')
					|| numberToValidate[x] == '-') {
				if (numberToValidate[x] == '-') {
					contadorSignoNegativo++;
				}
				output = 1;
			} else {
				output = 0;
				break;
			}
			if (contadorSignoNegativo > 1) {
				output = 0;
				break;
			}
		}
	}
	return output;
}

int utn_getFloat(char *msg, char *msgError, float *pResultado, int reintentos) {
	int output = -1;
	char bufferFloat[20];
	if (msg != NULL && msgError != NULL && pResultado != NULL
			&& reintentos > 0) {
		do {
			printf("%s", msg);
			if (!(myGets(bufferFloat, sizeof(bufferFloat)))
					&& utn_isFloatNumber(bufferFloat)) {
				output = 0;
				*pResultado = atof(bufferFloat);
			} else {
				reintentos--;
				if (reintentos > 0) {
					printf("%s: %d", msgError, reintentos);
				}
			}
		} while (output != 0 && reintentos > 0);
	}
	return output;
}

int utn_isFloatNumber(char *numberToValidate) {
	int output = 0;
	unsigned int contadorSignoNegativo = 0;
	unsigned int contadorPunto = 0;
	if (numberToValidate != NULL) {
		for (int x = 0; numberToValidate[x] != '\0'; x++) {
			if ((numberToValidate[x] >= '0' && numberToValidate[x] <= '9')
					|| (numberToValidate[x] == '.' || numberToValidate[x] == '-')) {
				if (numberToValidate[x] == '-') {
					contadorSignoNegativo++;
				}
				if (numberToValidate[x] == '.') {
					contadorPunto++;
				}
				output = 1;
			} else {
				output = 0;
				break;
			}
			if (contadorSignoNegativo > 1 || contadorPunto > 1
					|| (contadorSignoNegativo == 1 && numberToValidate[0] != '-')) {
				output = 0;
				break;
			}
		}
	} // fin IF GENERAL
	return output;
}
