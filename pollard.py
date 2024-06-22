from math import gcd
from sympy import isprime
from Crypto.PublicKey import RSA


# Pollard prime factorization algorithm
def pollard(n, e):
    a = 2
    i = e
    
    while True:
        a = (a**i) % n
    
        # finding gcd of a-1 and n
        d = gcd((a-1), n)
        i += 1
    
        if d > 1:
            return d
        
        
with open('public.pem', 'r', encoding='utf8') as f:
    key_encoded = f.read()

pubkey = RSA.importKey(key_encoded)
   
# Driver code
n = pubkey.n
e = pubkey.e
num = n
    
# list for prime factors
ans = []

while True:
    d = pollard(num, e)
    
    # add obtained factor to list
    ans.append(d)
    
    # reduce n
    r = int(num/d)
    
    # check for prime using sympy
    if isprime(r):
    
        # both prime factors obtained
        ans.append(r)
    
        break

    num = r
   
# print the result
print("Prime factors of", n, "are", *ans)