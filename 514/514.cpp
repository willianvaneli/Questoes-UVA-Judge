#include <iostream>
#include <stack>
using namespace std;


// A ideia do desafio é descobrir se o trem pode ser reorganizado com uma única passada, o teste é feito com uma pilha (dica dada já no nome da cidade PopPush).
// Como base a ideia -> caso o próximo número lido seja maior que o anterior adicionar a pilha até o mesmo e retira-lo o próximo número pode ser maior, caso menor pode ser somente em 1 unidade.

int main() {
	int tam;
	scanf("%d",&tam);
	while (tam) {
		int trem[1000];
		scanf("%d",&trem[0]);
		while (trem[0]) {
			stack<int> pilha;
			bool passagem = false;

			for (int i = 1; i < tam; i++)
				scanf("%d",&trem[i]);

			
			int inicio = 1;
			for (int j = 0; j < tam; j++) {
				if (trem[j] < inicio) {
					// Caso o item topo da pilha não seja igual o do trem seria necessário outra passagem para ordenar
					if (!pilha.empty() && pilha.top() == trem[j])
						pilha.pop();
					else {
						passagem = true;
						break;
					}
				} else {
					for (int k = inicio; k <= trem[j]; k++)
						pilha.push(k);
					pilha.pop();
					inicio = trem[j] + 1;
				}
			}
			if (passagem){
				printf("No\n");
			}else{
				printf("Yes\n");
			}
			scanf("%d",&trem[0]);
		}
		printf("\n");

		scanf("%d",&tam);
	}
	return 0;
}