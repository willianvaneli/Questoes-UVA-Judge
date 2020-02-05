#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;


int lstItens[101][100] = {{0}};

void verificaNo(int *lstRes[],int *lstVisitados[],int nTeste){
	if (*lstVisitados[nTeste] != 1){
        *lstVisitados[nTeste] = 1;
        int i = 0;
		while( lstItens[nTeste][i] != 0){
			*lstRes[lstItens[nTeste][i]] = 1;
			verificaNo(lstRes,lstVisitados,lstItens[nTeste][i]);
        }
    }
}

int main() {
	int i,j,count,tam,no,noAlcancado,testes,teste;
	
	
	// recebendo o valor da sequencia inicial
	scanf("%d",&tam);
	while (tam!=0){
		
        i=0;
        while(i < tam+2){
            j = 0;
            while(j<tam+2){
                lstItens[i][j] = 0;
                j++;
            }
            i++;
        }

		//Populando a lista de numeros e ao mesmo tempo pegando a quantidade maxima de numero repetido
        scanf("%d",&no);
        while ( no != 0){
            i = 0;
            scanf("%d",&noAlcancado);
            if (lstItens[no][0]!=0){
                while(lstItens[no][i]!=0){
                    i++;
                }
            }
            while (noAlcancado != 0){
                lstItens[no][i] = noAlcancado;
                i++;
                scanf("%d",&noAlcancado);
            }
            scanf("%d",&no);
        }

        scanf("%d",&testes);
        while(testes--){
            //Criar duas listas, uma para visitados e outro para itens que foram alcancados, e seta todos valores de posicao como zero
            int lstRes[tam+1]={0};
            int lstVisitados[tam+1]={0};

            scanf("%d",&teste);
            // Verifica a partir do no de entrada todos os nos que podem ser alcancados
            verificaNo(&lstRes,&lstVisitados,teste);


            // Percorre o resultado e formata a saida, realizando a contagem dos itens que nao foram alcancados
            count = 0;
            string strRes();
            i = 1;
            while(i < tam){
                if(lstRes[i] == 0 ){
                    strRes = strRes + ' ' + to_string(i);
                    count++;
                }
                i++;
            }
            char c[5];
            sprintf(c, "%i", count);
            strRes = c + strRes;
            printf(strRes);

        }

		scanf("%d",&tam);
		if(tam != 0){
			printf("\n");
		}
	}
	
}