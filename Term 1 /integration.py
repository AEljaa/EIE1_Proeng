x1 = float(input('x1='))
x2 = float (input('x2='))
delta=0.00001
area=0
while(x1<x2):
    area+=delta*(x1)**2
    x1+=delta

print(area)