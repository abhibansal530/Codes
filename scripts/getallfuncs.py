#!/usr/bin/python
import sys

if len(sys.argv)<=1:
    print "No input file"
    sys.exit(0)

fil = open(sys.argv[1],"r")
temp = fil.read()
code = temp.split('\n')
result = []
notWanted = ['if' , 'else', 'elif','typedef','switch','enum','=']
l = len(code)
i = 0

while(i<l):
    if( len(code[i]) > 0 and code[i][0] == '{' ):
        j = i-1
        while(j > 0):
            if(len(code[j]) > 0 and ( code[j][0] == '}' or code[j][len(code[j])-1] == ';') ):
                break
            else:
                j-=1
        for k in range(j+1,i):
            if len(code[k]) > 0:
                if(code[k][0] == '/' and code[k][1] == '/'): #line comment
                    continue
                elif(code[k][0] == '#'):     #not valid
                    continue
                elif(code[k][0] == '/' and code[k][1] == '*'): #block comment
                    while(True):
                        le = len(code[k])
                        flag = 0
                        if(le>0 and code[k][le-1] == '/' and code[k][le-2] == '*'):
                            k+=1
                            flag = 1
                            break
                        else:
                            k+=1
                    if flag:
                        break
                else:
                    break
        isFunction = True
        for j in notWanted:     #check if given line is function
            if j in code[k]:
                isFunction = False
                break
        if '(' not in code[k]:    #can't be a function
            isFunction = False
        if isFunction:
            print code[k][:code[k].find('(')],'\n'
    i+=1

