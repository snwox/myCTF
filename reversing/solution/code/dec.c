#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef unsigned char SNWO;
int main(void){
  SNWO code1[]={
86,27,99,246,233,136,36,51,216,27,3,243,34,236,182,105,135,89,70,
211,68,53,150,88,178,25,17,179,7,229,71,104,222,155,167,34,5,229,
58,104,3,155,34,179,40,185,70,61,68,80,115,70,34,236,198,61,68,208,
34,179,54,133,182,101,158,136,54,22,173,149,34,59,134,89,147,86,167,
136,132,101,228,89,34,179,11,244,17,123,34,206,19,211,68,245,68,59,87,
155,35,86,39,244,34,95,68,206,102,214,71,244,17,83,228,213,233,34,103,134,0
  };
  SNWO *_Dest=(SNWO*)malloc(sizeof(char)*strlen(code1));
  strcpy(_Dest,code1);
  int i=1;
  SNWO temp;
  int first=_Dest[strlen(code1)-1]>>4&0xff;
  int second=_Dest[strlen(code1)-1]<<4&0xff;
  temp=first|second;
  code1[0]=temp;
  for(;_Dest[i]!=0;i++){
    if(i%2==0){ // ROR -> ROL
      int first=_Dest[i-1]<<(i%8)&0xff;
      int second=_Dest[i-1]>>(8-(i%8))&0xff; 
      temp=first|second;
      code1[i]=temp;
    }
    else if(i%3==0){ // ROL -> ROR
      int first=_Dest[i-1]>>(i%8)&0xff;
      int second=_Dest[i-1]<<(8-(i%8))&0xff;
      temp=first|second;
      code1[i]=temp;
    }
    else if(i%5==0){ // ROR -> ROL
      int first=_Dest[i-1]<<(i%8)&0xff;
      int second=_Dest[i-1]>>(8-(i%8))&0xff;
      temp=first|second;
      code1[i]=temp;
    }
    else if(i%7==0){ // ROL -> ROR
      int first=_Dest[i-1]>>(i%8)&0xff;
      int second=_Dest[i-1]<<(8-(i%8))&0xff;
      temp=first|second;
      code1[i]=temp;
    }
    else{ //RORL
      int first=_Dest[i-1]>>4&0xff;
      int second=_Dest[i-1]<<4&0xff;
      temp=first|second;
      code1[i]=temp;
    }
  }
  printf("%s",code1);
}