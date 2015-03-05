#fruta = "manga"
fruta = raw_input("digite uma fruta\n")
#preco = 16.24
#print "Digite o preco"
preco = input("digite o preco\n")
peso = 2.3

print "voce comprou " + str(peso) + " kilos de " + fruta
print "o valor total e " + str(preco * peso)

if preco > 100.0 and fruta == "manga":
    print "vou chamar o procon"
elif preco > 10:
    print "Isso eh um absurdo pra um banana"
elif preco > 5:
    print "Isso eh um roubo"
else:
    print "Show de bola"


