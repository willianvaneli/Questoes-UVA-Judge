import sys

def main():
	
	arquivo = ''
	casos = int(input())
	lin = input()
	while casos != 0:
		pedacos = []
		lin = input()
		while lin != '':
			pedacos.append(lin)

			try:
				lin = input()
			except EOFError:
				break
		
		for i in range(0,len(pedacos)-1):
			for j in range(i+1,len(pedacos)):
				if len(pedacos[i]) < len(pedacos[j]):
					pedacos[i] , pedacos[j] = pedacos[j] ,pedacos[i]


		while len(pedacos) != 1:	
			inteiro = True
			a = pedacos[0]
			b = pedacos[1]
			if len(a) == 1:
				if b == '0':
					pedacos[0] = b + a
				else:
					pedacos[0] += b
				pedacos.pop(1)
			elif b not in a:
				i = len(b) -1
				while i > 0 and inteiro:
					if a[len(a)-i:] == b[:i]:
						pedacos[0] += b[i:]
						inteiro = False
						pedacos.pop(1)
					i-=1
				if inteiro:
					i = 1
					while i < len(b) and inteiro:
						if a[:len(b)-i] == b[i:]:
							pedacos[0] = b[:i] + a
							inteiro = False
							pedacos.pop(1)
					i+=1
				
				if inteiro:
					if b == '0':
						pedacos[0] = b + a
					else:
						pedacos[0] += b
					pedacos.pop(1)

			else:
				pedacos.pop(1)
		
		print(pedacos[0])

		casos -=1
		if casos !=0:
			print("")



    
if __name__ == "__main__":
    main()
