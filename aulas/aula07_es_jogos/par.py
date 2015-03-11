#/usr/bin/python3

opcao1 = raw_input()
num1 = input()
num2 = input()

soma = (num1 + num2)
if opcao1 == "par" and soma % 2 == 0 or \
   opcao1 == "impar" and soma % 2 == 1:
    print "jog1"
else:
    print "jog2"

