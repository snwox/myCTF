//gcc -fno-stack-protector bof.c -o bof
#include<stdio.h>

int main(void){
	char buf[60];
	scanf("%64s",buf);
	printf("%s",buf);
}
