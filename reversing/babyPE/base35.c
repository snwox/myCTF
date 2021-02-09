#include<stdio.h>
 
#include<string.h>
 
void dec(char ar[]) {
    char t[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
}
void encode(char * data, char * result, int bufSize) {
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    int count = 0;
    int buffer = data[0];
    int next = 1;
    int bitsLeft = 8;
    while (count < bufSize && (bitsLeft > 0 || next < 32)) {
        if (bitsLeft < 5) {
            if (next < 32) {
                buffer <<= 8;
                buffer |= data[next++] & 0xFF;
                bitsLeft += 8;
            } else {
                int pad = 5 - bitsLeft;
                buffer <<= pad;
                bitsLeft += pad;
            }
        }
        int index = 0x1F & (buffer >> (bitsLeft - 5));
        bitsLeft -= 5;
        result[count++] = table[index];
    }
    if (count < bufSize) {
        result[count] = '\000';
    }
}
int main(void) {
    char ar[32];
    char ar2[60];
    scanf("%s", ar);
    encode(ar, ar2, 60);
    if (!strcmp(ar2, "KNHFOT33EFPWIMDZGB2WW3RQO5PUEQBEIUZTEX3BNZSF6UCFH56Q")) {
        printf("ohOhohOhHoHoOhOh correct flag~");
    }
}