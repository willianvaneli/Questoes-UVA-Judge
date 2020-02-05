#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

char texto[100000];

int main() {
    while (scanf("%s", texto) != EOF) {
        int tam = strlen(texto);
        list<char> saida;
        list<char>::iterator texto_agr;
        texto_agr = saida.begin();
        saida.clear();

        for (int i = 0; i < tam; i++) {
            if (texto[i] == ']') texto_agr = saida.end();
            else if (texto[i] == '[') texto_agr = saida.begin();
            else saida.insert(texto_agr, texto[i]);
        }
        for (texto_agr = saida.begin(); texto_agr != saida.end(); texto_agr++) printf("%c", *texto_agr);
        printf("\n");
    } 
    return 0;
}