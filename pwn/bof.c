//gcc -fno-stack-protector bof.c -o bof
#include<stdio.h>

int main(void){
	char buf[64];
	write(1,"input msg >",11);
	gets(buf);
}
