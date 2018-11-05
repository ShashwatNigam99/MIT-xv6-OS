#include "types.h"
#include "stat.h"
#include "user.h"


void inverter (char *str){
  int i;
  for(i=0;str[i]!='\0';i++){
    if(str[i] >= 'a' && str[i] <= 'z')
       str[i] = str[i] - 32;
    else if(str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
  }
  printf(1,"%s ",str);
}

int main(int argc, char *argv[])
{
  int i;
  for(i = 1; i < argc; i++)
    inverter(argv[i]);
  printf(1,"\n");
  exit();
}
