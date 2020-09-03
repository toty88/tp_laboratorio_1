#include<stdio.h>

int fac(int n);
int main(void){

	int n;
	int resu;
	printf("Ingrese un numero: ");
	scanf("%d", &n);
	resu = fac(n);
	printf("\nel fac de %d es %d\n", n, resu);

	return 0;

}

int fac(int n){
	int resu;
	if(n == 1){
		return 1;
	}
	resu = n * fac(n-1);
	return resu;
}


