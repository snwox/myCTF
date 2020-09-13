f=open("flagpicture.bmp","rb")
f1=open("out","wb")

key='youfound!'

header=f.read()
bmp=header[0x36:]
header=header[:0x36]
c=0
data=b''
for i in range(len(bmp)):
    data+=bytes([ord(key[c%9])^bmp[i]])
    c+=1

f.close()
f1.write(header+data)
f1.close()