
def identificar(codigo, pessoa):
    cont = 0
    for c in pessoa:
        if c in codigo:
            cont += 1
    if cont == len(pessoa):
        return "boss"
    elif float(cont)/len(pessoa) > 0.5:
        return "ultron"
    return "pessoa"


def main():
    codigo = raw_input()
    lista = raw_input().split(" ")
    res = ""
    for pessoa in lista:
         res = res + identificar(codigo, pessoa) + " "
    nres = res[:-1]

    print nres

main()
