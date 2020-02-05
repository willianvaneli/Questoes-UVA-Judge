import sys

def main():
	
	testes = []

	casos = int(input())
	lin = input()
	while casos != 0:
		times = {}
		saida = {}
		lin = input()
		while lin != '':
			lst = lin.split(" ")
			time = int(lst[0])
			questao = int(lst[1])
			tempo = int(lst[2])
			resultado = lst[3]

			if time not in times:
				qt = {}
				penalidade = 0
				if resultado == 'I':
					penalidade = 20
					saida[time] = [0,0]
				elif resultado == 'C':
					saida[time] = [1,tempo]
				else:
					saida[time] = [0,0]
				qt[questao] = [resultado,penalidade]
				times[time] = qt
			elif questao not in times[time]:
				penalidade = 0
				if resultado == 'I':
					penalidade = 20
				elif resultado == 'C':
					if time not in saida:
						saida[time] = [1,tempo]
					else:
						saida[time][0]+=1
						saida[time][1]+=tempo
				times[time][questao] = [resultado,penalidade]
			#Caso exista o time e já houve tentativa de responder a questão
			else:
				if times[time][questao][0] != 'C':
					if resultado == 'C':
						#times[time][questao][0]=tempo <- não precisa
						times[time][questao][0]=resultado
						if time not in saida:
							saida[time] = [1,tempo+times[time][questao][1]]
						else:
							saida[time][0]+=1
							saida[time][1]+=tempo+times[time][questao][1]
					elif resultado == 'I':
						times[time][questao][1]+=20
			try:
				lin = input()
			except EOFError:
				break
		lstSaida = []
		for time in sorted(saida, key = saida.get, reverse = True):
			lstSaida.append([time,saida[time][0],saida[time][1]])
		
		for i in range(0,len(lstSaida)-1):
			for j in range(i+1,len(lstSaida)):					
				if lstSaida[i][1] == lstSaida[j][1]:
					if lstSaida[i][2] > lstSaida[j][2]:
						aux = lstSaida[i]
						lstSaida[i] = lstSaida[j]
						lstSaida[j] = aux
					elif (lstSaida[i][2] == lstSaida[j][2]) and (lstSaida[i][0] > lstSaida[j][0]):
						aux = lstSaida[i]
						lstSaida[i] = lstSaida[j]
						lstSaida[j] = aux

		for i in lstSaida:
			print("%d %d %d"%(i[0],i[1],i[2]))

		casos -=1
		if casos !=0:
			print("")



    
if __name__ == "__main__":
    main()
