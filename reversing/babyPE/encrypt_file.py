with open("base35.c","r") as f:
    data=f.read()

key=b'helloworld'
l=len(key)
dt=[]
c=0
for i in range(len(data)):
    dt.append(ord(data[i])^key[c%l])
    c+=1
print(dt)
f.close()