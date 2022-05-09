#!/usr/bin/python3

import base64

flag = 'ETSIIT_CTF{B64_15_N0T_CRYPT}'
encoded = flag.encode('ascii')

def b64e(a):
    return base64.b64encode(a)

for i in range(25):
    encoded = b64e(encoded)

print(encoded)
