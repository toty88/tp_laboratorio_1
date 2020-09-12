#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
int mainMenu(int flag, float numeroUno, float numeroDos){

	int unsigned opt;
		printf("##### CALCULADORA UTN FRa - TP1 #####\n\n");
	if(flag == 0){
			printf("(1). Ingresar Operando A\n"
			"(2). Ingresar Operando B\n"
			"(3). Calcular todas las Operaciones\n");
		printf("\t(a). Calcular la Suma (A+B)\n");
		printf("\t(b). Calcular la Resta (A-B)\n");
		printf("\t(c). Calcular la Division (A/B)\n");
		printf("\t(d). Calcular el Producto (A*B)\n");
		printf("\t(e). Calcular los Factoriales (A!&B!)\n");
	}
	else if(flag == 1){
		printf("(1). Ingresar Operando A "
			"\n\t(*) Operando A: %.2f\n"
			"(2). Ingresar Operando B: "
			"\n\t(*) Operando B:\n"
			"(3). Calcular todas las Operaciones\n", numeroUno);
		printf("\t(a). Calcular la Suma (%.2f + B)\n", numeroUno);
		printf("\t(b). Calcular la Resta (%.2f - B)\n", numeroUno);
		printf("\t(c). Calcular la Division (%.2f / B)\n", numeroUno);
		printf("\t(d). Calcular el Producto (%.2f * B)\n", numeroUno);
		printf("\t(e). Calcular los Factoriales (%.2f & B)\n", numeroUno);
	}else{
			printf("(1). Ingresar Operando A "
			"\n\t(*) Operando A: %.2f\n"
			"(2). Ingresar Operando B: "
			"\n\t(*) Operando B: %.2f\n"
			"(3). Calcular todas las Operaciones\n", numeroUno, numeroDos);
		printf("\t(a). Calcular la Suma (%.2f + %.2f)\n", numeroUno, numeroDos);
		printf("\t(b). Calcular la Resta (%.2f - %.2f)\n", numeroUno, numeroDos);
		printf("\t(c). Calcular la Division (%.2f / %.2f)\n", numeroUno, numeroDos);
		printf("\t(d). Calcular el Producto (%.2f * %.2f)\n", numeroUno, numeroDos);
		printf("\t(e). Calcular los Factoriales (%.2f & %.2f)\n", numeroUno, numeroDos);
	}
	printf("(4). Informar Resultado\n"
		"(5). Salir ---> ");
	scanf("%d", &opt);
	return opt;
}
