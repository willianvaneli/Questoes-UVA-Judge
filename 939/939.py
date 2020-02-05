import sys

def main():
	pessoas = {}
	filhos = {}

	avaliacoes = int(input())

	while avaliacoes != 0:
		
		pessoa = input().split()
		if pessoa[1] == 'dominant' or pessoa[1] == 'recessive'  or pessoa[1] == 'non-existent' :
			pessoas[pessoa[0]] = pessoa[1]
		elif pessoa[1] in filhos:
			filhos[pessoa[1]].append(pessoa[0])
		else:
			filhos[pessoa[1]] = []
			filhos[pessoa[1]].append(pessoa[0])
		avaliacoes -=1

	rest = []
	for filho in filhos:
		rest.append([filho,filhos[filho][0],filhos[filho][1]])

	i = 0
	while len(rest) > 0:		
		if (i >= len(rest)):
			i = 0
		if (rest[i][1] in pessoas) and (rest[i][2] in pessoas):
			genePai = pessoas[rest[i][1]]
			geneMae = pessoas[rest[i][2]]

			if genePai == geneMae:
				pessoas[rest[i][0]] = genePai
			elif (genePai == 'dominant' or geneMae == 'dominant') and (genePai == 'recessive' or geneMae == 'recessive'):
				pessoas[rest[i][0]] = 'dominant'
			elif (genePai == 'dominant' or geneMae == 'dominant') and (genePai == 'non-existent' or geneMae == 'non-existent'):
				pessoas[rest[i][0]] = 'recessive'
			elif (genePai == 'recessive' or geneMae == 'recessive') and (genePai == 'non-existent' or geneMae == 'non-existent'):
				pessoas[rest[i][0]] = 'non-existent'
			
			rest.pop(i)
		i+=1	

	lst = []
	
	for i in pessoas.keys():
		lst.append(i)
	
	lst.sort()

	for i in lst:
		print("%s %s"%(i,pessoas[i]))



    
if __name__ == "__main__":
    main()
