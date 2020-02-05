#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	int i,N,C,espantalhos,count,mid,dir;
	char let;
	
	// recebendo o valor da sequencia inicial
	scanf("%d",&N);
	i=1;
	while (i < N+1){
		espantalhos = 0;
		scanf("\n%d\n",&C);
		
		while(C > 0){
			scanf("%c",&let);
			while(let == '#' && C>0){
				scanf("%c",&let);
				C--;
			}

			if(C>0){
				espantalhos++;
				
				if(C>1){
					scanf("%c",&let);
					scanf("%c",&let);
					C-=2;
				}else if(C>0){
					scanf("%c",&let);
					C--;
				}
			}

			C--;
		}
		
		
		
		printf("Case %d: %d\n",i,espantalhos);
		i++;
		
	}
	
}