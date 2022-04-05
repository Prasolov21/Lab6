import math
F=[math.tan(0),math.tan(math.pi/8),math.tan(2*(math.pi/8)),math.tan(3*(math.pi/8))]
xi=[0,math.pi/8,2*(math.pi/8),3*(math.pi/8)]
x=(3*math.pi)/16
P=1
d=0
L=0
for i in range (0,4):
    P=1
    for j in range (0,4):
        if i!=j:
            P=P*((x-xi[j])/(xi[i]-xi[j]))
    L=L+(F[i]*P)
    print(i,j,F,P,L)
y=math.tan(x)
print(y-L)