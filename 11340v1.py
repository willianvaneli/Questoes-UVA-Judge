import sys

def main():
    casos = int(input())
    while casos > 0:
        qtLetras = int(input())
        dic = {}
        valor = 0
        while qtLetras > 0:
            lt = input().split(' ')
            dic [lt[0]] = int(lt[1])
            qtLetras -=1
        
        texto = int(input())
        while texto > 0:
            linha = input()
            for i in linha:
                if i in dic.keys():
                    valor += dic[i]
            texto -=1
        casos -=1
        valor = valor/100
        print("%.2f$"%valor)
        

if __name__ == "__main__":
    main()
