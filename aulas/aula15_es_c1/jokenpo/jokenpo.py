#r rock p paper s scissors
op1 = raw_input().lstrip().rstrip()
op2 = raw_input()

if op1 == op2:
    print "empate"
elif op1 == "p" and op2 == "r":
    print "op1"
elif op1 == "r" and op2 == "s":
    print "op1"
elif op1 == "s" and op2 == "p":
    print "op1"
else:
    print "op2"

