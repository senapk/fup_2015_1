vel = float(input())
tempo = int(input())
consumo = float(input())

tempo = float(tempo)/60

desemp = vel * tempo / consumo
print ("%.2f km/l") %(desemp)
