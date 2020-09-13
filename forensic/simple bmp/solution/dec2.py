f=open("out","rb")

header=f.read()
data=header[0x36:] # 헤더는 암호화가 안되어 있으므로, 데이터만 분리해 복호화
header=header[:0x36]

f.close()

key='youfound!'
c=0
dec=b''
for i in range(len(data)): #key 와 xor 연산으로 복호화
    dec+=bytes([ord(key[c%9])^data[i]])
    c+=1

flag_zip=dec[90000:] #파일의 데이터크기 뒤에있는 zip 파일을 분리 

f=open("flag.zip","wb") #새파일 작성
f.write(flag_zip)
f.close()