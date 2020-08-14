#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  
 char* filename = argv[1];
 FILE* file = fopen(filename, "r");
 int x;
 fscanf(file, "%d\n", &x);

 char function[5];
 int temporaryBit;
 int v;
 int n;
 

while(fscanf(file, "%s\t%d\t%d\n", function, &n, &v) == 3)
{
  if(function[0] == 'g')
  {
    temporaryBit = 1;
    temporaryBit = temporaryBit << n;
    printf("%d\n",(x & temporaryBit) && 1);
  }
  else if(function[0] == 's')
  {
     int temp = 1;
     if(v == 0){
       
       temp = temp << n;
       temp = ~temp;
       x = temp & x;
      }
      else{
       temp = temp << n;
       x = temp | x;
      }
  

  printf("%d\n", x);
  }
  else if(function[0] == 'c')
  {
    temporaryBit = 1;
    temporaryBit = temporaryBit << n;
    x = x ^ temporaryBit;
    printf("%d\n", x);
  } 

 }

  
  fclose(file);

}


