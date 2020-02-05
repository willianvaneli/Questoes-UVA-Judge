import sys

# A SOLUÇÃO PROPOSTA É PARECIDA COM O PATIENCE SORT ONDE CRIAMOS VÁRIAS PILHAS PARA ORDENAÇÃO

def main():
    lin = input()
    caso = 1
    while lin != 'end':
        pilhas = []
        pilhas.append([])
        pilhas[0].append(lin[0])
        
        for i in range(1,len(lin)):
            j = 0
            while j < len(pilhas):
                if str(pilhas[j][-1]) >= str(lin[i]):
                    pilhas[j].append(lin[i])
                    break
                j+=1
            if j == len(pilhas):
                aux = []
                aux.append(lin[i])
                pilhas.append(aux)


        print ("Case %d: %d"%(caso,len(pilhas)))
        caso += 1
        lin = input()
        

if __name__ == "__main__":
    main()
