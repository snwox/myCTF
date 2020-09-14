#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef unsigned char SNWO;

SNWO Flag[]="SNWO{This_is_Fake_Flag}";

void _mein(SNWO Flag[]){
  int i=0;
  
  while(i!=strlen(Flag)&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void __mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ___mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ____mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void _____mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ______mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
SNWO* enc(SNWO Str[]){
  SNWO *TEMP=(SNWO*)malloc(sizeof(SNWO)*strlen(Str));
  strcpy(TEMP,Str);
  int i=1;
  SNWO temp;
  SNWO first=TEMP[0]>>4&0xff;
  SNWO second=TEMP[0]<<4&0xff;
  temp=first|second;
  TEMP[strlen(Str)]=temp; //NULL 문자자리에 첫번째꺼 암호화
  TEMP[strlen(Str)+1]=0; //NULL + 1 에 NULL문자. (unsigned 로 선언되어 공간 넉넉)
  //실행후 1 늘어남
  while(i<strlen(TEMP)-1){
    if(i%2==0){ // ROR
      first=TEMP[i]>>(i%8)&0xff;
      second=TEMP[i]<<(8-(i%8))&0xff; 
      temp=first|second;
      TEMP[i-1]=temp;
    }
    else if(i%3==0){ // ROL
      first=TEMP[i]<<(i%8)&0xff;
      second=TEMP[i]>>(8-(i%8))&0xff;
      temp=first|second;
      TEMP[i-1]=temp;
    }
    else if(i%4==0){
      temp=(TEMP[i]^2+2*2)/2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      TEMP[i]=temp;
    }
    else if(i%5==0){ // ROR
      first=TEMP[i]>>(i%8)&0xff;
      second=TEMP[i]<<(8-(i%8))&0xff;
      temp=first|second;
      TEMP[i-1]=temp;
    }
    else if(i%6==0){
      temp=(TEMP[i]^2+2*2)/2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      TEMP[i]=temp;
    }
    else if(i%7==0){ // ROL
      first=TEMP[i]<<(i%8)&0xff;
      second=TEMP[i]>>(8-(i%8))&0xff;
      temp=first|second;
      TEMP[i-1]=temp;
    }
    else if(i%8==0){
      temp=(TEMP[i]^2+2*2)/2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      TEMP[i]=temp;
    }
    else if(i%9==0){
      temp=(TEMP[i]^2+2*2)/2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      temp+=(TEMP[i]^2+2*2)%2;
      TEMP[i]=temp;
    }
    else{ //RORL
      first=TEMP[i]>>4&0xff;
      second=TEMP[i]<<4&0xff;
      temp=first|second;
      TEMP[i-1]=temp;
    }
    i+=1;
  }
  TEMP[strlen(Str)-1]=TEMP[strlen(Str)];
  TEMP[strlen(Str)]=0;
  return TEMP;
}
void _______mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void _________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void __________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ___________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;

}
void ____________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void _____________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ______________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void _______________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void ________________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}
void _________________mein(SNWO Flag[]){
  int i=0;
  
  while(i!=Flag[i]&&i!=99999&&i!=Flag[i]^i+99999&&i==i){
    Flag[i]=Flag[i]^0x54^0x32^0x10;i+=1;
  }
  ;
}

int main(void){
  SNWO mix[100];
  SNWO code1[]={
86,27,99,246,233,136,36,51,216,27,3,243,34,236,182,105,135,89,70,
211,68,53,150,88,178,25,17,179,7,229,71,104,222,155,167,34,5,229,
58,104,3,155,34,179,40,185,70,61,68,80,115,70,34,236,198,61,68,208,
34,179,54,133,182,101,158,136,54,22,173,149,34,59,134,89,147,86,167,
136,132,101,228,89,34,179,11,244,17,123,34,206,19,211,68,245,68,59,87,
155,35,86,39,244,34,95,68,206,102,214,71,244,17,83,228,213,233,34,103,134,0
  };
  SNWO *hello=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *mixed=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *python=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *And=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *c=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *came=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *here=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *a=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *b=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *under=(SNWO*)malloc(sizeof(SNWO)*20);
  SNWO *fmt=(SNWO*)malloc(sizeof(SNWO)*20);
  const SNWO* cmp[11]={
    "hello","mixed","python","And","c","came","here","a","b","under","fmt"
  };
  SNWO* IN[11]={
    hello,mixed,python,And,c,came,here,a,b,under,fmt
  };
  SNWO*INPUT=malloc(sizeof(SNWO)*strlen(code1));
  puts("Welcome to Cython!!\n");
  puts("CCCCCCC   Y     Y   TTTTTTT   H     H    OOOOO    N     N");
  puts("C           Y Y        T      H     H   O     O   N N   N");
  puts("C            Y         T      HHHHHHH   O     O   N  N  N");
  puts("C            Y         T      H     H   O     O   N   N N");
  puts("CCCCCCC      Y         T      H     H    OOOOO    N     N\n");

  puts("Please Input correct variables to print with Cython !!");
  puts("Correct variables will print correct Flag~");
  puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  puts("!!!!!!!! All variables aren't over length 8 !!!!!!!!");
  puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  puts("Cython will execute this command\n");
  puts(">>> print(f'{fmt}{a}{hello}{under}{mixed}{under}{python}{under}{And}{under}{c}{under}{came}{under}{here}{b}')\n");

  int i=0;
  for(i=0;i<11;i++){
    printf("%s -> ",cmp[i]);
    scanf("%s",IN[i]);
  }
  _mein(Flag);
  __mein(Flag);
  ___mein(Flag);
  ____mein(Flag);
  _____mein(Flag);
  ______mein(Flag);
  _______mein(Flag);
  ________mein(Flag);
  _________mein(Flag);
  __________mein(Flag);
  ___________mein(Flag);
  ____________mein(Flag);
  _____________mein(Flag);
  ______________mein(Flag);
  _______________mein(Flag);
  ________________mein(Flag);
  _________________mein(Flag);

  puts("[~~~] running python code... based on user input");
  puts("[~~~] >>> print(f'{fmt}{a}{hello}{under}{mixed}{under}{python}{under}{And}{under}{c}{under}{came}{under}{here}{b}')");
  printf("[~~~] >>> %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",IN[10],IN[7],IN[0],IN[9],IN[1],IN[9],IN[2],IN[9],IN[3],IN[9],IN[4],IN[9],IN[5],IN[9],IN[6],IN[8]);
  
  puts("\n[~~~] Comparing with correct variables....");
  sprintf(INPUT,"hello=\"%s\";mixed=\"%s\";python=\"%s\";And=\"%s\";c=\"%s\";came=\"%s\";here=\"%s\";a=\"%s\";b=\"%s\";under=\"%s\";fmt=\"%s\";",IN[0],IN[1],IN[2],IN[3],IN[4],IN[5],IN[6],IN[7],IN[8],IN[9],IN[10]);
  INPUT=enc(INPUT);
  if(!strcmp(INPUT,code1)){
    puts("Oh, Correct Flag!!!");
    printf("Take you flag again >>> %s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n",IN[10],IN[7],IN[0],IN[9],IN[1],IN[9],IN[2],IN[9],IN[3],IN[9],IN[4],IN[9],IN[5],IN[9],IN[6],IN[8]);
  }
  else{
    puts("No..No.. incorrect variables");
  }

  fflush(stdin);
  puts("\n\nPRESS ANI KEY TO CONTINUE ");
  getchar();
  return 0;
}
