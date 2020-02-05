def f(mat_entrada):
    mat_result = [[0,0,0], [0,0,0], [0,0,0]]

    mat_result[0][0] = (mat_entrada[1][0] + mat_entrada[0][1]) % 2
    mat_result[1][0] = (mat_entrada[0][0] + mat_entrada[1][1] + mat_entrada[2][0]) % 2
    mat_result[2][0] = (mat_entrada[1][0] + mat_entrada[2][1]) % 2
    mat_result[0][1] = (mat_entrada[0][0] + mat_entrada[1][1] + mat_entrada[0][2]) % 2
    mat_result[1][1] = (mat_entrada[2][1] + mat_entrada[1][0] + mat_entrada[0][1] + mat_entrada[1][2]) % 2
    mat_result[2][1] = (mat_entrada[1][1] + mat_entrada[2][2] + mat_entrada[2][0]) % 2
    mat_result[0][2] = (mat_entrada[0][1] + mat_entrada[1][2]) % 2 
    mat_result[1][2] = (mat_entrada[1][1] + mat_entrada[2][2] + mat_entrada[0][2]) % 2
    mat_result[2][2] = (mat_entrada[2][1] + mat_entrada[1][2]) % 2

    return mat_result

def main():
    mat_entrada = [[0,0,0], [0,0,0], [0,0,0]]
    #print("Numero de testes:")
    num_testes = int(input())
    resultado = []

    while (num_testes != 0):
        linha_vazia = input()
        for i in range(0, 3):
            #for j in range(0, 3):
                #mat_entrada[i][j] = int(input())
            linha = list(map(int, input()))
            mat_entrada[i][0] = linha[0]
            mat_entrada[i][1] = linha[1]
            mat_entrada[i][2] = linha[2]
        #print(mat_entrada)

        resposta = -1
        while True:
            tudozero = True
            for i in range(0,3):
                for j in range(0,3):
                    if mat_entrada[i][j] != 0: tudozero = False
            if tudozero == True: break

            mat_entrada = f(mat_entrada)
            resposta = resposta + 1

        resultado.append(resposta)
        #print("Resposta:", resposta)
        num_testes = num_testes - 1
    for i in range(0, len(resultado)): print(resultado[i])

if __name__ == "__main__":
    main()