import sys
import ipaddress

input = sys.stdin
T = int(input.readline())
for t in range(T):
    addr = input.readline()
    print("{:0128b}".format(int(ipaddress.ip_address(addr.strip()))))
