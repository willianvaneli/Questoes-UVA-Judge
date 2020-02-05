#include <cstdio>
#include <iostream>

using namespace std;

// Após tentar com força bruta e bater de cara no TLE
// Resolvi guardar o "rastro" do horário em um array de inteiros, o que me deu um erro onde não conseguia executar o programa pois não conseguia instanciar o mesmo.
// Após isso mudei o array de inteiros para um array de booleanos, assim foi possivel descobrir se um horário coincidia com outro.

int main(){
    int conflict;
    long long int rep,nrep,hini,hfim,repeticao,it;
    bool horarios[1000001];
    
    scanf("%lld %lld",&nrep,&rep);
    
    while ((rep!=0) || (nrep!=0)) {
        conflict = 1;
        
        for (int b = 0; b<1000001; b++){
            horarios[b] = false;
        }
        
        int z = 0;
        while (z < nrep ){
            scanf("%lld %lld",&hini,&hfim);
            it = hini;
            while (it < hfim && conflict){
                if(horarios[it]){
                    conflict = 0;
                }else{
                    horarios[it] = true;
                }
                it++;
            }
            z ++;
        }
        z = 0;
        while (z < rep ){
            scanf("%lld %lld %lld",&hini,&hfim,&repeticao);
            while (hini < 1000001 && conflict){
                it = hini;
                while ((it < hfim) && conflict && (it < 1000001)){
                    if(horarios[it]){
                        conflict = 0;
                    }else{
                        horarios[it] = true;
                    }
                    it++;
                }
                hini += repeticao;
                hfim += repeticao;
            }
            z ++;
        }


        if(conflict){
            printf("NO CONFLICT\n");
        }else{
            printf("CONFLICT\n");
        }
        scanf("%lld %lld",&nrep,&rep);
    }


    return 0;
}