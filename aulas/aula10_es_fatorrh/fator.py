def efilho(mae, pai, filho):
	a = mae[0]
	b = mae[1]
	c = pai[0]
	d = pai[1]
	e = filho[0]
	f = filho[1]
	if (f == a or f == b ) and (e == c or e == d) or \
	   (e == a or e == b ) and (f == c or f == d):
		return True
	else:
		return False


lista = raw_input().split(" ")

pai = lista[0]
mae = lista[1]
filho = lista[2]

if len(pai) == 1:
   pai = "O" + pai
if len(mae) == 1:
   mae = "O" + mae
if len(filho) == 1:
   filho1 = "O" + filho
   filho2 = filho + filho

#if efilho(mae, pai, filho1) == False and \
#   efilho(mae, pai, filho2) == False:
#	print "Nao"
#else:
#	print "Sim"

if efilho(mae, pai, filho1) or efilho(mae, pai, filho2):
	print "Sim"
else:
	print "Nao"
