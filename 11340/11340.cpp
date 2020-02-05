#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


int main(){
    int casos,qtLetras,peso,texto;
    unsigned char let,letra;
    string linha;
    int ascii[256];
    unsigned long long valor;

    

    scanf("%d\n",&casos);
    while (casos > 0) {
        valor = 0;
        
        scanf("%d\n",&qtLetras);
        for(int i=0; i<256; i++){
            ascii[i] = 0;
        }
        
        while (qtLetras > 0){
            scanf("%c %d\n",&let,&peso);
            int v = (int)let;
            ascii[v] = peso;
            
            qtLetras --;
        }



        scanf("%d\n",&texto);
        while (texto > 0){
        
            scanf("%c",&letra);
			while ( letra != '\n') {
				valor += ascii[(int) letra];
                scanf("%c",&letra);
			}

            texto--;
        }
        casos --;
        

        printf("%.2f$\n",valor / 100.0);
        
    }


    return 0;
}