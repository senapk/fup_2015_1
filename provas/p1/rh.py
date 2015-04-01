def eh_filho(mae, pai, son):
    a = mae[0]
    b = mae[1]
    c = pai[0]
    d = pai[1]
    e = son[0]
    f = son[1]

    if ((e == a or e == b) and (f == c or f == d)) or\
       ((f == a or f == b) and (e == c or e == d)):
        return True
    return False


lista = raw_input().split(" ")
mae = lista[0]  #se int -0.5
pai = lista[1]
son = lista[2]

if len(mae) == 1:
    mae = 'O' + mae
if len(pai) == 1:
    pai = 'O' + pai
if len(son) == 1:
    son1 = 'O' + son
    son2 = son + son
else:
    son1 = son
    son2 = son

if(eh_filho(mae, pai, son1) or eh_filho(mae, pai, son2)):
    print "Sim"
else:
    print "Nao"

