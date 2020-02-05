import sys
import math



def merge(a,b):
    for i in b:
        if i not in a:
            a.append(i)
    return a

def main():
    
    casos = int(input())
    input()
    while casos > 0 :
        
        maiorLet = input()
        lstLigacoes = []
        lstLigacoes.append([maiorLet])
        # Adicionando todas as letras ate a maior em um lista
        it = ord(maiorLet) -1
        while it > 64:
            lstLigacoes.append([chr(it)])
            it -=1

        ligacao = input()
        while ligacao!= "":
            try:
                # Caso a ligacao for da letra para ela mesma nao e necessario nenhuma acao, Caso nao, e passado um loop para achar a ocorrencia da primeira letra e verificada se a segunda
                # letra esta na mesma lista, caso nao e setado o boleano que informa a necessidade do merge entre as listas que contem as letras
                if ligacao[0] != ligacao[1]:
                    adicionado = False
                    nmerge = False
                    i = 0
                    while i < len(lstLigacoes) and not adicionado:
                        if ligacao[0] in lstLigacoes[i]:
                            # Caso a segunda letra nao estar na mesma lista e necessario o merge das listas
                            if ligacao[1] not in lstLigacoes[i]:
                                lstLigacoes[i].append(ligacao[1])
                                nmerge = True
                            adicionado = True
                        i+=1
                    # Caso haja necessidade do merge a lista de ligacoes e percorrida ate encontrar a posicao da outra lista que fara parte do merge, tendo em vista que a primeira ja temos em i - 1
                    if nmerge:
                        for j in range(0,len(lstLigacoes)):
                            if (ligacao[1] in lstLigacoes[j]) and (j != i-1):
                                lstLigacoes[j] = merge(lstLigacoes[j],lstLigacoes[i-1])
                                lstLigacoes.pop(i-1)
                                break
                ligacao = input()
            except:
                break
        print(len(lstLigacoes))

        
        casos -=1
        if casos != 0:
            print("")
    
        



        

if __name__ == "__main__":
    main()