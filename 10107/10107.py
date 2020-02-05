#A = [1,3,4,60,70,50,2]
#A = [1,2,3,4,50,60,70]

#print(len(A))
#print(n//2)
def main():
    A = [] #cria lista vazia
    while True: #enquanto não parar de digitar
        try:
            A.append(int(input())) #adiciona numero à lista
        except EOFError:
            break
        A.sort()  #ordena a lista
        n = len(A)
        if n%2==1:  #se for impar
            mediana = A[(n//2)]
        else:  #se for par
            mediana = (A[(n//2)-1]+A[(n//2)])//2
        print(mediana)

if __name__ == "__main__":
    main()