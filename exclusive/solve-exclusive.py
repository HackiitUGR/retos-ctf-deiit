#!/usr/bin/python3

enc = '6g0;z ,p74H\x07B^\x13\x1e\x00Y+\x031_V\x1a\x10A\x1a\x02G\x11\x17N'
key = 's3cr3t'

flag = ''

for i in range(len(enc)):
    flag += chr(ord(enc[i])^ord(key[i%len(key)]))

print("The flag is:", flag)
