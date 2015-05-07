
svetor = raw_input().split(" ")
vetor = []
for elem in svetor:
    vetor.append(int(elem))

#maior = vetor[0]
##busca pelo elemento
#for elem in vetor:
    #if elem > maior:
        #maior = elem

#print maior

#busca pelo indice
maior = vetor[0]
indice = 0
for i in range (1, len(vetor)):
    if vetor[i] > maior:
        maior = vetor[i]
        indice = i

print maior, indice

