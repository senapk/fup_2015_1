#parte 1 - Carregar a entrada em um vetor de floats
#5 1.65 1.38 1.49 1.65 1.90

alturas_string = raw_input().split(" ") #vetor de strings

alturas_float = [] #vetor de floats
qtd = int(alturas_string[0])

cont = 1 #primeiro elemento que representa uma altura
while cont <= qtd: #varrer todos os elementos que representam uma altura
    alturas_float.append(float(alturas_string[cont])) #float
    cont += 1

#parte 2 - Calcular a media 
soma = 0
for elem in alturas_float:
    soma += elem
#aqui eu ja tenho a soma
media = float(soma) / len(alturas_float)
print "%.2f" % media


#parte 3 - Imprimir pra cada soldado se ele e P, M ou G

for elem in alturas_float:
    if elem < media:# essa e a parte de voces
        print "P",
    elif elem == media:
        print "M",
    else:
        print "G",
