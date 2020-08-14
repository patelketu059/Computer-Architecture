#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	struct node* next;
	int value;
} node;
  
node** table;

void create()
{
	table = malloc(sizeof(node*) * 10000);
	int k;
	for(k = 0; k < 10000; k++)
	{
		table[k] = NULL;
	}
}


int hashKey(int value)
{
	int key = value % 10000;
	if(key < 0)
	{
		key += 10000;
	}
	return key;
}


int search(int value)
{
	int key = hashKey(value);
	node* find = table[key];
	while(find != NULL)
	{
		if((*find).value == value)
			{
				return 1;
			}
			find = (*find).next;
	}
	return 0;
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


int insert(int value)
{
	int key = hashKey(value);
	node* newNode = malloc(sizeof(node));
	(*newNode).value = value;
	if(table[key] != NULL)
	{
		(*newNode).next = table[key] ;
		table[key] = newNode;
		return 1;		
	}	
	else
	{
		(*newNode).next = NULL;
		table[key] = newNode;
		return 0;
	}
}

int main(int argc, char** argv)
{
	char* filename = argv[1];
	FILE* file = fopen(filename, "r");
	int collision = 0;
	int searchCount = 0;
	char action;
	int value;
	create();
	while(fscanf(file, "%c\t%d\n", &action, &value) == 2)
	{
		if(action == 'i')
		{
			if(insert(value) == 1)
			{
				collision++;
			}
		}
		else if(action == 's')
		{
			if(search(value) == 1)
			{
				searchCount++;
			}
		}
	}

	printf("%d\n%d\n", collision, searchCount);
	
	int m;
	for(m = 0; m < 10000; m++)
	{
		node* temp = table[m];
		freeAll(temp);
	}
	free(table);


	fclose(file);
	return 0;

}
