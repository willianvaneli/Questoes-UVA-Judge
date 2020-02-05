#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int i,count,N,val,nlst,tam;
	
	
	// recebendo o valor da sequencia inicial
	scanf("%d",&N);
	while (N!=0){
		int array[10000];
		i=0;
		//Zerando array
		while (i<10000){
			array[i]=0;
			i++;
		}
		//Declarando fila prioritaria em ordem crescente
		priority_queue <int, vector<int>, greater<int>> fila;

		//Populando a lista de numeros e ao mesmo tempo pegando a quantidade maxima de numero repetido
		i = 0;
		while (i < N){
			scanf("%d",&val);
			fila.push(val);
			array[val]+=1;
			i++;
		}

		//Pegando valor maximo dentro do array, foi necessario buscar o valor dentro do ponteiro
		int* pos = max_element(array,array+10000);
		nlst = *pos;

		//Criado uma matriz, chamei de pilha porque a matriz foi utilizada para que cada linha fosse uma pilha ordenada
		int pilha[nlst][fila.size()];
		tam = fila.size();

		//Realizando o preenchimento de cada pilha da seguinte maneira
		//A cada numero era adicionado a uma linha da matriz e pulado para a proxima linha
		i=0;
		count=0;
		while( count < tam){
			if(!fila.empty()){
				pilha[i][count] = fila.top();
				fila.pop();
			}else{
				pilha[i][count] = 0;
			}

			i++;
			if(i==nlst){
				count++;
				i=0;
			}
		}


		//Impressao das pilhas
		i=0;
		printf("%d\n",nlst);
		while(i<nlst){
			printf("%d",pilha[i][0]);
			for(int k=1; k<tam; k++){
				if (pilha[i][k]!=0){
					printf(" %d",pilha[i][k]);
				}
			}
			printf("\n");
			i++;
		}
		

		scanf("%d",&N);
		if(N != 0){
			printf("\n");
		}
	}
	
}