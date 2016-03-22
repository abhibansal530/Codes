#!/usr/bin/python
import random as r
t = 100
m=15
for i in range(0,t):
    a=r.randrange(1,m)
    d=r.randrange(0,10)
    L=r.randrange(1,100)
    R=r.randrange(L,101)
    print a,d,L,R
