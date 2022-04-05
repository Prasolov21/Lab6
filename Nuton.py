import math
F=[math.tan(0),math.tan(math.pi/8),math.tan(math.pi/3),math.tan(3*(math.pi/8))]
xi=[0,math.pi/8,(math.pi/3),3*(math.pi/8)]
x=(3*math.pi)/16
for i in range (0,4):
    print(x-xi[i],i)
for i in range(0,3):
    print(F[i]-F[i+1],i)
    print(xi[i]-xi[i+1],i)
P=F[0]
P=P+((x-xi[0])*((F[0]-F[1])/(xi[0]-xi[1])))
P=P+((x-xi[0])*(x-xi[1])*((((F[0]-F[1])/(xi[0]-xi[1]))-((F[1]-F[2])/(xi[1]-xi[2])))/(xi[0]-xi[2])))
P=P+((x-xi[0])*(x-xi[1])*(x-xi[2])*((((((F[0]-F[1])/(xi[0]-xi[1]))-((F[1]-F[2])/(xi[1]-xi[2])))/(xi[0]-xi[2]))-(((((F[1]-F[2])/(xi[1]-xi[2]))-((F[2]-F[3])/(xi[2]-xi[3])))/(xi[1]-xi[3]))))1/(xi[0]-xi[3])))
y=math.tan(x)
d=y-P
print(P,y,d)