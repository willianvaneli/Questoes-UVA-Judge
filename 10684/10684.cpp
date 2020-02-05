#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;



int main() {
	int maiorGanho,ganhoAtual,N,aposta;
	
	// recebendo o valor da sequencia inicial
	scanf("%d",&N);
	while (N!=0){
		maiorGanho=0;
		ganhoAtual = 0;
		while(N >0){
			scanf("%d",&aposta);
			ganhoAtual += aposta;
			if (ganhoAtual > 0){
				if(ganhoAtual > maiorGanho){
					maiorGanho = ganhoAtual;
				}
			}else{
				ganhoAtual = 0;
			}
			N--;
		}
		if ( maiorGanho > 0){
			printf("The maximum winning streak is %d.\n",maiorGanho);
		}else{
			printf("Losing streak.\n");
		}
		scanf("%d",&N);
	}
	
}