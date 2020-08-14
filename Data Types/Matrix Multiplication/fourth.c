#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv)
{
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    int matrix1r;
    int matrix2r;
    int matrix1c;
    int matrix2c;
    int** matrix1;
    int** matrix2;



    int i;
    int k;





    fscanf(file, "%d\t%d", &matrix1r, &matrix1c);
    matrix1 = malloc(sizeof(int*)*matrix1r);
    for(i = 0; i < matrix1r; i++)
    {
        matrix1[i] = malloc(sizeof(int)*matrix1c);

        for(k = 0; k < matrix1c; k++)
        {
            int currValue;
            fscanf(file, "%d", &currValue);
            matrix1[i][k] = currValue;
        }
    }








    fscanf(file, "%d\t%d", &matrix2r, &matrix2c);
    if(matrix1c != matrix2r)
    {
        printf("bad-matrices\n");
        return 0;
    }




    
    
    matrix2 = malloc(sizeof(int*)*matrix2r);
    for(i = 0; i < matrix2r; i++)
    {
        matrix2[i] = malloc(sizeof(int) * matrix2c);

        for(k = 0; k < matrix2c; k++)
        {
            int currValue;
            fscanf(file, "%d", &currValue);
            matrix2[i][k] = currValue;
        }
    } 

    //Done extracting data






    int m;
    int** finalArray= malloc(sizeof(int*) * matrix1r);
    for(i = 0; i < matrix1r; i++)
    {
        finalArray[i] = malloc(sizeof(int)*matrix2c);
        for(k = 0; k < matrix2c; k++)
        {
            int currValue = 0;
            for(m = 0; m < matrix1c; m++)
            {
                currValue += matrix1[i][m] * matrix2[m][k];
            }

            finalArray[i][k] = currValue;
        }
    }


    for(i = 0; i < matrix1r; i++)
    {
        for(k = 0; k < matrix2c; k++)
        {
            printf("%d", finalArray[i][k]);
            if(k != matrix2c - 1)
            {
                printf("\t");
            }
        }
        printf("\n");
    }


    for(i = 0; i < matrix1r; i++)
    {
        free(matrix1[i]);
        free(finalArray[i]);
    }




    for(m = 0; m < matrix2r; m++)
    {
        free(matrix2[m]);
    }




    free(matrix1);
    free(finalArray);
    free(matrix2);





    fclose(file);
    return 0;
}
