from Crypto.Util import number
from binascii import hexlify,unhexlify

def gcd(a, b):
    while b!=0:
        a, b = b, a%b
    return a

def decrypt(pk, ciphertext):
    key, n = pk
    plain=unhexlify(hex(ciphertext**key%n)[2:].encode())
    return plain

def encrypt(pk, plaintext):
    key, n = pk
    cipher=int(hexlify(plaintext.encode()).decode(),16)**key%n
    return cipher

def get_private_key(e, tot):
    k=1
    while (e*k)%tot != 1 or k == e:
        k+=1
    return k

def get_public_key(tot):
    e=5

    while e<tot and gcd(e, tot)!=1:
        e += 1
    return e
#출처 : https://wkdtjsgur100.github.io/RSA-algorithm/
#nuber.getPrime(8)
M=['Sm','_a','ll']
p1=[179,137,239]
q2=[251,227,257]
n=[] 
totient=[] 
e=[] 
d=[]
enc=[]
dec=[]
for i in range(3):
    n.append(p1[i]*q2[i])
    totient.append((p1[i]-1)*(q2[i]-1))
    e.append(get_public_key(totient[i]))
    d.append(get_private_key(e[i],totient[i]))
    enc.append(encrypt((e[i],n[i]),M[i]))
    dec.append(decrypt((d[i],n[i]),enc[i]))
    print(f'{i+1} -> (n,e,m) = ({hex(n[i])},{e[i]},{hex(enc[i])})')
    print(f'{M[i]} ** {hex(e[i])} % {hex(n[i])} = {hex(enc[i])}')
    print(f'{"="*0x30}')
