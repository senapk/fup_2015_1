valores = raw_input("digite a 3 valores").split(" ")
a = int(valores[0])
b = int(valores[1])
c = int(valores[2])

if a < b and b < c or \
   c < b and b < a:
    print "sim"
else:
    print "nao"

