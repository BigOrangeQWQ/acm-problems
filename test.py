import math
x=0

for i in range(100,1000):
    cnt=math.pow(i%100//10,3)+math.pow(i%10,3)+math.pow(i//100,3)
    cnt=int(cnt)
    
    if cnt == i:
        x=x+1
        if x == 1:
            print(i,end="")
        else :
            print(","+str(i),end="")