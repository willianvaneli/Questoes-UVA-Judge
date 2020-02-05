import sys
import math

          
def calculaDistancia(pontoA , pontoB):
    return math.sqrt(((pontoA[0] - pontoB[0])**2) + ((pontoA[1] - pontoB[1])**2))



def main():
    # Será utilizada uma lista de pontos onde cada ponto é uma tupla contendo x e y
    
    casos = int(input())
    
    while casos > 0 :
        input()
        # Recebendo numero de pontos e criando a lista de pontos
        lstPontosInicial = []
        qtPontos = int(input())
        while qtPontos > 0:
            lt = list(map(float , input().split() ))
            ponto = (lt[0],lt[1])
            lstPontosInicial.append(ponto)
            qtPontos -=1
        
        # Agora enquanto a lista de pontos iniciais contiver um ponto ...
        # Verifique o ponto mais proximo dentre os pontos visitados e adicione na lista de visitados, retire-o da lista de pontos iniciais
        distanciaTotal = 0
        lstVisitados = [lstPontosInicial[0]]
        lstPontosInicial.pop(0)

        while len(lstPontosInicial) > 0:
            dist = sys.float_info.max
            ponto = (0,0)
            for i in lstPontosInicial:
                for j in lstVisitados:
                    dt = calculaDistancia(i,j)
                    if dt < dist:
                        dist = dt
                        ponto = i
            distanciaTotal += dist
            lstVisitados.append(ponto)
            lstPontosInicial.remove(ponto)
        
        print("%.2f"%(distanciaTotal))

        
        casos -=1
        if casos != 0:
            print("")
    
        



        

if __name__ == "__main__":
    main()