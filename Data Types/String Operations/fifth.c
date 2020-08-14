#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int checkVowel(char a) 
{
    if((a == 'a' || a== 'e' || a == 'i' || a== 'o' || a == 'u'
        || a== 'A' || a== 'E' || a== 'i' || a== 'O' || a== 'U'))
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int main(int argc, char** argv) 
{
    int length = argc - 1;

    int i;
    int k;
    int count = 0;
    for (i = 0; i < length; i++) 
    {
        char* stri = argv[1 + i];
        int currStrLen= strlen(stri);
        for (k = 0; k < currStrLen; k++) 
        {
            if (checkVowel(stri[k])) 
            {
                count++;
            }
        }
    }


    int counter = 0;
    char* word = malloc(sizeof(char) * (count + 1));
    word[count] = '\0';
    for (i = 0; i < length; i++) 
    {
        char* stri = argv[1 + i];
        int currStrLen= strlen(stri);
        for (k = 0; k < currStrLen; k++) 
        {
            if (checkVowel(stri[k])) 
            {
                word[counter++] = stri[k];
            }
        }
    }

    printf("%s\n", word);

    free(word);

    return 0;
}

