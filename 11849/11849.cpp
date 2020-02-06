#include <iostream> 
using namespace std; 
#define MAXN 1000010 
main() { 
    int qtdJack,qtdJill,jack[MAXN],jill[MAXN]; 
    int i,j,contador; 
    while (cin >> qtdJack >> qtdJill) { 
        if (qtdJack==0 && qtdJill==0) 
            break; 

        for (i=1;i<=qtdJack;i++) 
            cin >> jack[i]; 

        for (i=1;i<=qtdJill;i++) 
            cin >> jill[i]; 
        contador = 0; 
        i = 1; 
        j = 1; 
        while (i<=qtdJack && j<=qtdJill) { 
            while (j<=qtdJill && jill[j]<jack[i]) 
                j++; 
                if (j>qtdJill) 
                    break; 
                    
                if (jack[i]==jill[j]) { 
                    contador++; 
                    j++; 
                }

                i++;
            }
            cout << contador << endl; 
        } 
}
