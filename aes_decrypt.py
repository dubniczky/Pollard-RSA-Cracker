from binascii import unhexlify
from Crypto.Cipher import AES


password=''
cipher=''


# Decrypt
cipher_bin = unhexlify(cipher)
cipher = AES.new(password, AES.MODE_ECB)
text = cipher.decrypt(cipher_bin)
print(text)
