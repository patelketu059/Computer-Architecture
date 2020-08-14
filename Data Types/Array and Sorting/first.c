#include <stdio.h>
#include <stdlib.h>


void ascendSort(int arr[], int l)
{   
    int i,k;
    int current;
    for (i = 0; i < l - 1; i++)
    {
       for (k = 0; k < l - 1; k++)
       {
           if (arr[k] > arr[k + 1])
           {
               current = arr[k];
               arr[k] = arr[k + 1];
               arr[k + 1] = current;
           }
       }
    }
    
}

void descendSort(int arr[], int l)
{
    int i,k;
    int current;
    for (i = 0; i < l - 1; i++)
    {
       for (k = 0; k < l - i-1; k++)
       {
         if (arr[k] < arr[k + 1])
           {
               current=arr[k];
               arr[k]=arr[k + 1];
               arr[k + 1]=current;
           }

       }
    }          
}




int main(int argc, char *argv[])
{
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    int elements;
    fscanf(file, "%d", &elements);
    int even = 0;
    int odd = 0;

    int *allElements = (int*) malloc(sizeof(int) * elements);



    int i;
    for(i = 0; i < elements; i++)
    {
        int currentNumber;
        fscanf(file, "%d", &currentNumber);
        if(currentNumber % 2 == 0)
        {
            even++;
        }      
        else
        {
            odd++;
        }
        allElements[i] = currentNumber;
    }
        
    int *evenArr = (int*) malloc(sizeof(int) * even);
    int eCounter = 0;    
    for(i = 0; i < elements; i++)
    {
        if(allElements[i] % 2 == 0)
        {
            evenArr[eCounter++] = allElements[i];
         
       }
    }

    int *oddArr = (int*) malloc(sizeof(int) * odd);
    int oCounter = 0;
    for(i = 0; i < elements; i++)
    {
        if(allElements[i] % 2 != 0)
        {
            oddArr[oCounter++] = allElements[i];
        }
    }

    
    ascendSort(evenArr, even);
    descendSort(oddArr, odd);

    for(i = 0; i < elements; i++)
    {
        if(i < even)
        {
            allElements[i] = evenArr[i];
        }
        else
        {   
            allElements[i] = oddArr[i - even];
        }
    }
    
        
    for(i = 0; i < elements; i++)
    {
        printf("%d", allElements[i]);
        if(i != elements - 1) 
            {
                printf("\t");
            }   
    }
     printf("\n");

     
    free(allElements);
    free(evenArr);
    free(oddArr);
    
   
    fclose(file);
    return 0;
}
