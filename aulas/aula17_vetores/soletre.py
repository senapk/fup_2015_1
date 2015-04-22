
texto = raw_input()
##############
i = 0
saida = "["
while i < len(texto) - 1:
    saida += texto[i] + "-"
    i += 1
saida += texto[-1] + "]"
###########
saida = "[" + texto[0]
for i in range(1, len(texto)):
    saida += '-' + texto[i]
saida += "]"
#######
saida = "["
for i in range(0, len(texto)):
    saida += texto[i]
    if(i != len(texto) - 1):
        saida += "-"
saida += "]"
########
saida = ""
for x in texto:
    saida += "-" + x
saida = "[" + saida[1:] + "]"
