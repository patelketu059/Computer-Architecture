#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
  
  int pairs = 0;
  int count = 0;
  unsigned short n = atoi(argv[1]);
  int i;
  unsigned short currentBit;
  unsigned short previousBit = 0;

  while(n)
  {
    currentBit = n & 1;
    if(previousBit && currentBit == 1)
    {
      previousBit = 0;
      pairs++;
    }
    else
    {
      previousBit = currentBit;
    }

    if(currentBit == 1)
    {
      count++;
    }
    n = n >> 1;
  }


  if(count % 2 == 0)
  {
    printf("Even-Parity\t%d\n",pairs);
  }
  else
  {
    printf("Odd-Parity\t%d\n",pairs);
  }

  



  return 0;
}
