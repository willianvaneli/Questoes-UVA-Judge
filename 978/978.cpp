#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int guerras,qtdcampo,val,qtdverde,qtdazul,menor,tam,v,a;
    
    
    scanf("%d\n",&guerras);
    while (guerras > 0) {
        scanf("%d %d %d\n",&qtdcampo,&qtdverde,&qtdazul);
        priority_queue<int> verde;
        priority_queue<int> azul;
        for (int i =0; i<qtdverde ; i++){
            scanf("%d\n",&val);
            verde.push(val);
        }
        for (int i =0; i<qtdazul ; i++){
            scanf("%d\n",&val);
            azul.push(val);
        }


        vector<int> vecVerde,vecAzul;

        while(!verde.empty() && !azul.empty()){
            menor = min(azul.size(),verde.size());
            menor = min(menor, qtdcampo);
            
            while (menor>0){
                //Pega os maiores valores, verifica o maior e põe em um vetor de elementos que já batalharam.
                int v = verde.top();
                verde.pop();
                int a = azul.top();
                azul.pop();
                if (v > a){
                    vecVerde.push_back(v-a);                    
                }else if (v < a){
                    vecAzul.push_back(a-v);
                }
                menor--;
                
            }
            tam = vecVerde.size();
            for (int i =0; i<tam ; i++){
                verde.push(vecVerde[i]);
            }

            tam = vecAzul.size();
            for (int i=0; i<tam ; i++){
                azul.push(vecAzul[i]);
            }

            vecAzul.clear();
            vecVerde.clear();

        }
        if (verde.empty() && azul.empty()){
            printf("green and blue died\n");
        }
		else if( verde.empty() && azul.size() != 0){
			printf("blue wins\n");
			while (!azul.empty()){
                printf("%d\n",azul.top());
                azul.pop();
            }
        }
		else if( verde.size() != 0 && azul.empty()){
			printf("green wins\n");
			while (!verde.empty()){
                printf("%d\n",verde.top());
                verde.pop();
            }
        }


        guerras --;
        if(guerras != 0){
            printf("\n");
        }
        
    }


    return 0;
}