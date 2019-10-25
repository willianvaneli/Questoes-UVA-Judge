import sys

def main():
    lst = input().split(' ')
    while lst[0] != '0':
        princesa = []
        principe = []
        tamX = 0
        tamY = 0
        princesa.append(int(lst[0]))
        princesa.append(int(lst[1]))
        princesa.append(int(lst[2]))
        x = int(lst[3])
        y = int(lst[4])
        if x > y:
            x,y = y,x
        princesa.sort()
        principe.sort()

        if princesa[1] > y:
            print("-1")
        elif princesa[2] > y:
            if princesa[1] > x:
                print("-1")
            else:
                val = princesa[1]+1
                while val == x or val == y or val == princesa[2]:
                    val+=1
                if val < 53:
                    print(val)
                else:
                    print('-1')
        else:
            if princesa[1] > x:
                val = princesa[2]+1
                while val == x or val == y:
                    val+=1
                if val < 53:
                    print(val)
                else:
                    print('-1')
            elif princesa[2]> x:
                val = princesa[1]+1
                while val == x or val == y or val == princesa[2]:
                    val+=1
                if val < 53:
                    print(val)
                else:
                    print('-1')
            else:
                val = 1
                while val == x or val == y or val == princesa[0] or val == princesa[1] or val == princesa[2]:
                    val+=1
                if val < 53:
                    print(val)
                else:
                    print('-1')
        lst = input().split(' ')     
        

if __name__ == "__main__":
    main()
