texto = raw_input()

#forma 1
print texto[::-1]

#forma 2
ind = len(texto) - 1
saida = ""
while ind >= 0:
    saida += texto[ind]
    ind -= 1
print saida

#forma 3
saida2 = ""
for i in range(len(texto) - 1, -1, -1):
    saida2 += texto[i]
print saida2

#forma 4 - nao funciona pra texto, mas funciona pra lista
for i in range(0, len(texto)/2):
    ultimo = len(texto) - 1 - i

    temp = texto[i]
    texto[i] = texto[ultimo] #nao funciona para texto
    texto[ultimo] = temp
print texto
