import sys

def main():
    while True:
        try:
            flag = True
            linha = input()
            lst = [int(i) for i in linha.split(' ')]
            lstRes = []
            if len(lst) > 3:
                for i in range(1,len(lst)-1):
                    dif = lst[i] - lst[i+1]
                    if dif < 0 :
                        dif = dif * -1
                    lstRes.append(dif)
                lstRes.sort()
                for i in range(0,len(lstRes)):
                    if lstRes[i] != i+1:
                        print("Not jolly")
                        flag = False
                        break
                if flag:
                    print("Jolly")
            elif len(lst) == 3:
                dif = lst[1] - lst[2]
                if dif < 0 :
                    dif = dif * -1
                if dif == 1:
                    print("Jolly")
                else:
                    print("Not jolly")
            else:
                print("Jolly")
        except EOFError:
            break
        

        

if __name__ == "__main__":
    main()
