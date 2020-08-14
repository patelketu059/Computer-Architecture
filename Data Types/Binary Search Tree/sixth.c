#include <stdio.h>
#include <stdlib.h>

typedef struct node {
      int value;
        struct node* right;
        struct node* left;

}node;




node* addNew(int value, node* head) 
{
 


    node *curr = head;
 
    node *tail = NULL;
    
 

    int a = 0;

    while (curr != NULL) 
    {
        if (value > (*curr).value) 
        {
          a = 1;
        } 
        else if (value < (*curr).value) 
        {
          a = -1;
        } 
        else 
        {
          a = 0;
        }

        if (a == 0) 
        {
          return head;
        }



        tail = curr;
        if (a < 0) 
        {
          curr = (*curr).left;
        } 
        else 
        {
          curr = (*curr).right;
        }
    }





    node* createNew = malloc(sizeof(node));
    (*createNew).left = NULL;
    (*createNew).right = NULL;
    (*createNew).value = value;



    

    if (tail == NULL) 
    {
      head = createNew;
    } 
    else if (a < 0) 
    {
      (*tail).left = createNew;
    } 
    else 
    {
      (*tail).right = createNew;
    }
    return head;
}






void freeTree(node* head) 
{


    if (head == NULL) 
    {
      return;
    }


    freeTree((*head).left);
    freeTree((*head).right);
    free(head);
}







void orderAndPrint(node* head) 
{
    if (head == NULL) 
    {
      return;
    }

    orderAndPrint((*head).left);
    printf("%d\t", (*head).value);
    orderAndPrint((*head).right);
}






int main(int argc, char* argv[]) {
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    node* head = NULL;
    int data;
    while (fscanf(file, "i\t%d\n", &data) == 1) 
    {
      head = addNew(data, head);
    }

    orderAndPrint(head);
    printf("\n");

    freeTree(head);
    fclose(file);
    return 0;
}

