from Crypto.PublicKey import RSA


with open('public.pem', 'r', encoding='utf8') as f:
    key_encoded = f.read()


pubkey = RSA.importKey(key_encoded)
print('N =', pubkey.n)
print('e =', pubkey.e)
