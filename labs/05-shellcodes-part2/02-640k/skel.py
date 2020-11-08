#!/usr/bin/env python

from pwn import *
import sys

# scanf is weird and can interfere with other reading functions
# to avoid that you should always send 4096 bytes to scanf (size of its internal buffer)
def scanf_pad(s):
    return s + b' ' * (4096 - len(s))

ret_offset = 0 # TODO 1: Find return address offset

p = process('640k')
# TODO 1: Use recvuntil, sendline and recvline to interact with the process

# TODO 1: Get leak from interaction

# TODO 2: Send stage 1
raw_input("Send stage 1?")

# TODO 2: Write stager shellcode
stager = asm("""
            nop
        """,arch = 'amd64')

nops = b'\x90' * (ret_offset - len(stager))

print(disasm(stager, arch='amd64'))
print("================")
print("stager len = {}".format(len(stager)))
print("================")

#stage1 = stager + nops + leak

# TODO 3
stage2 = asm("""
            nop
        """,arch = 'amd64')

print(disasm(stage2, arch='amd64'))
print("================")
print("stager2 len = {}".format(len(stage2)))
print("================")

#p.sendline(stage1)

# give the exit command so the program jumps into the shellcode
p.send(scanf_pad(b'3')) # Exit

# TODO 3: Send stage 2
raw_input("Send stage 2?")
#p.sendline(stage2)
p.interactive() # You should get a shell here :-)
