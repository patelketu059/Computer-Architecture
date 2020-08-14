#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  unsigned short n = atoi(argv[1]);
  unsigned short bin[16];
  unsigned short reversebin[16];
  

  int i;
  for(i = 0; i <= 15; i++)
  {
    bin[i] = n & 1;
    reversebin[15-i] = n & 1;
    n = n >> 1;
  }



  int j;
  for(j = 0; j <= 15; j++)
  {
    if((bin[j] & 1) == (reversebin[j] & 1))
    {
      if(j == 15)
      {
        printf("Is-Palindrome\n");
      }
      continue;

    }
    else
    {
      printf("Not-Palindrome\n");
      break;
    }
  }


return 0;
}