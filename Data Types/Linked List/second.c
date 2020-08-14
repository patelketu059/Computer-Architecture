#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node* next;
} node;


node* addNode(node* snake, int value)
{
    node* tail = NULL; 
    node* head = snake;
    while(head != NULL)
    {
        if(((tail == NULL) || (tail != NULL && value >= (*tail).value)) && (*head).value >= value)
        {
            break;
        }

        tail = head;
        head = (*head).next;
	}
        node* insertNode = malloc(sizeof(node));
        (*insertNode).value = value;
        (*insertNode).next = head;


        if(tail == NULL)
        {
            snake = insertNode;            
        }
        else
        {
            (*tail).next = insertNode;
        }
        return snake;
}

node* removeNode(node* snake, int value)
{
    node* head = snake;
    node* tail = NULL;

    while(head != NULL)
    {
        if((*head).value == value)
        {
            break;
        }
        tail = head;
        head = (*head).next;
    }

    if(head != NULL)
    {
        if(tail != NULL)
        {
            (*tail).next = (*head).next;
        }
        else
        {
            snake = (*head).next;
        }
        free(head);
    }

    return snake;
}

void freeAll(node* snake)
{
    if(snake == NULL)
    {
        return;
    }
    node* head = snake;
    while((*head).next != NULL)
    {
        node* next = (*head).next;
        free(head);
        head = next;
    }
    free(head);

}

void printAll(node* snake)
{
	node* head = snake;	
	int last;
	while(head != NULL)
	{
		if(head == snake || last != (*head).value)
		{
			printf("%d", (*head).value);
			if((*head).next != NULL)
			{
				printf("\t");
			}
			else
			{
				printf("\n");
			}
		}
		  last = (*head).value;
         head = (*head).next;
	}

}

int size(node* snake)
{
    node* head = snake;
    int length = 0;
    while(head != NULL)
    {
        length++;
        head = (*head).next;
    }
    return length;
}


int main(int argc, char **argv)
{
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {   
        printf("Error\n");
        return 0;
    }

    char action;
    int value;
    node* ptr = NULL;


	
    while((fscanf(file, "%c\t%d\n", &action, &value)) == 2)
    {
        if(action == 'i')
        {
            if(ptr == NULL)
            {
                ptr = malloc(sizeof(node));
                (*ptr).value = value;
                (*ptr).next = NULL;
            }
            else
            {
                ptr = addNode(ptr,value);
            }
        }
        else if(action =='d')
        {
            ptr = removeNode(ptr,value);
        }
    }

       int length = size(ptr);
       printf("%d\n", length);
       if(length > 0)
       {
            printAll(ptr);
       }

       freeAll(ptr); 
         
        fclose(file);
        return 0;
}
