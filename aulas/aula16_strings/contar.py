
frase = raw_input()
letra = raw_input()

qtd = count(letra, frase)
cont = 0

for c in frase:
    if (c.lower() == letra) or (c.upper() == letra):
        cont += 1

print cont


