#!/usr/bin/env python
#r rock, p paper, s scissors

op1 = raw_input()
op2 = raw_input()

if op1 == op2:
    print "empate"
elif (op1 == "r" and op2 == "s") or (op1 == "s" and op2 == "p") or \
    (op1 == "p" and op2 == "r"):
    print "jog1"
else:
    print "jog2"

