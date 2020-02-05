#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int pesos[20000];
int somas[20000];

int main() {
    
    while (scanf("%d", &n) != EOF) { //atribuindo numero de dimensoes (enquanto n parar de escrever)
        int n_vert = pow(2,n); //cubos tem 2^(dimensao) vertices
        for (int i = 0; i < n_vert; i++) {
            scanf("%d", &pesos[i]);   //atribuindo os pesos fornecidos
        }

        
        for (int i = 0; i < n_vert; i++) { //percorrendo lista de vertices
            int soma_vert = 0;
            for (int j = 0; j < n; j++) { //percorrendo vizinhos de cada vertice (cada vertice tem n vizinhos)
                int pos_vizinho = i^(1<<j); //formula para detectar os vizinhos
                int peso_vizinho = pesos[pos_vizinho];
                soma_vert = soma_vert + peso_vizinho; //acumula a soma dos vizinhos
            }
            somas[i] = soma_vert; //atribui a soma dos vizinhos de cada vertice
        }

        int soma_max = 0;
        for (int i = 0; i < n_vert; i++) { //percorrendo lista de vertices
            for (int j = 0; j < n; j++) { //percorrendo vizinhos de cada vertice (cada vertice tem n vizinhos)
                int pos_vizinho = i^(1<<j); //formula para detectar os vizinhos
                    if (soma_max < somas[i] + somas[pos_vizinho]) //compara soma atual com a maior soma ate agr
                        soma_max = somas[i] + somas[pos_vizinho];
            }
        }
        printf("%d\n", soma_max);
    }
    return 0;
}