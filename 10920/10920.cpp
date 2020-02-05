#include <cstdio>
#include <math.h>


int main(){
    long long int tam,val,col,lin,canto,atual;
    scanf("%lld %lld",&tam,&val);
    while (tam != 0) {
        
        canto = pow(val, 0.5);
        if (canto%2 == 0){
            canto -=1;
        }
        if (tam != 1){
            lin = col = canto + (tam-canto)/2;

            atual = canto * canto;

            if ((val > atual + canto * 2 + 2) && ( atual != val)){
                atual += canto * 2 + 2;
                col -= canto;
                lin -= canto;
                if (val < atual + canto + 1){
                    if (val < atual + canto/2){
                        for (int k=0; k < canto+1; k++){
                            if (atual != val){
                                col +=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }else{
                        atual += canto/2;
                        col += canto/2;
                        for (int k=0; k < canto+1; k++){
                            if (atual != val){
                                col +=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }
                }else{
                    col += canto + 1;
                    atual += canto + 1;
                    if (val < atual + canto/2){
                        for (int k=0; k < canto; k++){
                            if (atual != val){
                                lin +=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }else{
                        lin += canto/2;
                        atual += canto/2;
                        for (int k=0; k < canto; k++){
                            if (atual != val){
                                lin +=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }
                }
            }else if ( atual != val){
                lin +=1;
                atual +=1;
                if (val < atual + canto){
                    if (val < atual + canto/2){
                        for (int k=0; k < canto; k++){
                            if (atual != val){
                                col -=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }else{
                        atual += canto/2;
                        col -= canto/2;
                        for (int k=0; k < canto; k++){
                            if (atual != val){
                                col -=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }
                }else{
                    col -= canto;
                    atual += canto;
                    if (val < atual + canto/2){
                        for (int k=0; k < canto + 1; k++){
                            if (atual != val){
                                lin -=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }else{
                        lin -= canto/2;
                        atual += canto/2;
                        for (int k=0; k < canto+1; k++){
                            if (atual != val){
                                lin -=1;
                                atual +=1;
                            }else
                                break;
                        }
                    }
                }
            }
        
            printf("Line = %lld, column = %lld.\n",lin,col);
        }else{
            printf("Line = 1, column = 1.\n");
        }


        scanf("%lld %lld",&tam,&val);
    }


    return 0;
}