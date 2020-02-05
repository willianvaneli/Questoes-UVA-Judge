#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;



int matIni[100][100];
int *preCalc;


int calcRet(int a,int b,int c, int d){
	int i,j;
	int resultado=0;
	if (c!=a){
		// Recupera valor da soma até a última linha e soma da linha atual
		resultado= preCalc[a*100 + b*100 + (c-1)*100 + d];
		for(j=b;j<d+1;j++)
			resultado+=matIni[c][j];
		preCalc[a*100 + b*100 + c*100 + d]= resultado;
		return resultado;
	}
	for(i=a;i<c+1;i++)
		for(j=b;j<d+1;j++)
			resultado+=matIni[i][j];
	preCalc[a*100 + b*100 + c*100 + d]= resultado;
	return resultado;
}



int main() {
	int cont,N, i,j,k,l,soma,somaMax;
	preCalc = (int*) malloc(100000000 * sizeof(int));
	// preenchendo a matriz inicial
	while (scanf("%d",&N)!=EOF){
		somaMax=INT_MIN;
		//Zerando preCalc
		memset(preCalc,1,100000000);
		for (i=0; i < N; i++)
			for (j=0; j < N; j++)
				scanf("%d",&matIni[i][j]);
		// loop para verificar cada retangulo possível
		for (i=0; i < N; i++)
		{
			for (j=0; j < N; j++)
				for (k=i; k<N;k++)
					for(l=j;l<N;l++)
					{
						soma=calcRet(i,j,k,l);
						if (soma>somaMax)
							somaMax=soma;
					}
		}
		printf("%d\n", somaMax);
	}
	free(preCalc);
	}