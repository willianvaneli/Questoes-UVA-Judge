import sys

#criar uma função recursiva que envia uma lista dos itens que já foram utilizados, o item a ser verificado e as regras

def busca(lstResI,lstItensI,item):
    lstRes = lstResI.copy()
    lstItens = lstItensI.copy()
    
    if(len(lstItens) == 1):
        lstRes.append(item[0])
        global lstFinal
        lstFinal.append(lstRes)
    else:
        lstItens.remove(item)
        pode = True
        for i in item[1]:
            #verificar que o item pode ser colocado naquela posição
            for k in lstItens:
                if k[0] == i:
                    pode = False
        
        if pode:
            lstRes.append(item[0])
            for k in lstItens:
                busca(lstRes,lstItens,k)
            

    



lstFinal = []

def main():
    # O item será uma lista composta de sua letra e de um sub lista com as letras que tem que estar antes dele
    
    casos = int(input())
    input()
    while casos > 0 :
        global lstFinal 
        lstFinal = []
        # Criando todos os itens com as letras de entrada
        lstItensInicial = []
        lstLet = input().split()
        for i in lstLet:
            item = [i,[]]
            lstItensInicial.append(item)
        

        # Recebe todas as regras e adiciona ao item especifico
        # Cada item tem uma lista de itens que são "menores" que o proprio
        # Enquanto a linha não vier vazia continua-se a procurar regras
        lin = input()    
        while( lin != ""):
            try:
                lstLinReg = lin.split()
                for j in lstLinReg:
                    reg = j.split("<")
                    for iterator in range(0,len(lstItensInicial)):
                        if  lstItensInicial[iterator][0] == reg[1]:
                            lstItensInicial[iterator][1].append(reg[0])
            
                lin = input()
            except:
                break
    

        
        # Inicia busca com todos os itens existentes
        for i in lstItensInicial:
            lstItensRestantes = lstItensInicial.copy()
            #lstItensRestantes.remove(i)
            busca([],lstItensRestantes,i)

        # Printa todos resultados possiveis caso exista
        lstFinal.sort()
        if len(lstFinal)>0:
            for i in lstFinal:
                saida = i[0]
                for z in range(1,len(i)):
                    saida = saida + " " + i[z]
                print(saida)
        else:
            print("NO")

        casos -=1
        if casos != 0:
            print("")
    
        



        

if __name__ == "__main__":
    main()