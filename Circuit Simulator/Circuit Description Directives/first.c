    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>



    typedef struct node{
    	struct node *next;
    	void *value;
    }node;

    typedef enum gate{
    	and,
    	or,
    	nand,
    	not,
    	xor,
    	nor
    }gate;



    typedef struct operation
    {
    	gate type;
    	int inputList1;
    	int inputList2;
    	int output;
    }operation;





   	gate setType(char* string)
   	{

   		if(strcmp(string, "XOR") == 0)
   		{
   			return xor;
   		}

   		if(strcmp(string, "NOT") == 0)
   		{
   			return not;
   		}

   		if(strcmp(string, "NAND") == 0)
   		{
   			return nand;
   		}

   		if(strcmp(string, "AND") == 0)
   		{
   			return and;
   		}

   		if(strcmp(string, "NOR") == 0)
   		{
   			return nor;
   		}

   		return or;
   		
   	}

   	node* delete(int delete, node* head)
   	{
   		int counter = 0;
   		node* tail = NULL;
   		node* ptr = head;

   		while(ptr != NULL)
   		{
   			if(counter != delete)
   			{
   				counter++;
   				tail = ptr;
   				ptr = (*ptr).next;
   			}
   			else
   			{
   				break;
   			}
   		}

   		if(ptr != NULL)
   		{
   			if(tail != NULL)
   			{
   				(*tail).next = (*ptr).next;
   			}
   			else
   			{
   				head = (*ptr).next;
   			}
   			free(ptr);
   		}

   		return head;

   	}

   	int evaluate(gate type, int inputList1, int inputList2)
   	{
   		if(type == and)
   		{
   			return inputList1 && inputList2;
   		}
   		else if(type == or)
   		{
   			return inputList1 || inputList2;
   		}
   		else if(type == nor)
   		{
   			return !(inputList1 || inputList2);
   		}
   		else if(type == xor)
   		{
   			return (!inputList1 && inputList2) || (!inputList2 && inputList1);
   		}
   		else if(type == not)
   		{
   			return !inputList1;
   		}
   		else
   		{
   			return !(inputList2 && inputList1);
   		}

   	}


   	node* insert(void *value, node* head)
   	{
   		node *tail = NULL;
   		node *ptr = head;
   		node *newIn = malloc(sizeof(node));

   		while(ptr != NULL)
   		{
   			tail = ptr;
   			ptr = (*ptr).next;
   		}

   		(*newIn).value = value;

   		(*newIn).next = ptr;
   		if(tail == NULL)
   		{
   			head = newIn;
   		}
   		else
   		{
   			(*tail).next = newIn;
   		}


   		return head;

   	}



   	int indexList(node* head, char* string)
   	{
   		node* ptr = head;
   		int index = 0;
   		while(ptr != NULL)
   		{
   			if(strcmp((char*)(*ptr).value, string) == 0)
   			{
   				return index;

   			}
   			index++;
   			ptr = (*ptr).next;
   		}
   		return -1;
   	}









    int main(int argc, char** argv) {

       char* filename = argv[1];
       FILE* file = fopen(filename, "r");
       if(file == NULL)
       {
       	fprintf(stderr, "Error: Please enter valid file name\n");
       	return 0;
       }


       char opTypeName[5];
       char inList1[10];
       char inList2[10];
       char outList[10];
       node *head = NULL;
       node *temp = NULL;


       int numberInputs;
       int numberOutputs;

       fscanf(file, "%*s %d", &numberInputs);
       char** inputList = (char**)malloc(sizeof(char*) * numberInputs);


       int k = 0;
       int i = 0;
       while(k < numberInputs)
       {
       		inputList[k] = (char*)malloc(sizeof(char) * 10);
       		fscanf(file, "%s", inputList[k]);
       		k++;
       }

      fscanf(file, "%*s %d", &numberOutputs);
       char** outputList = (char**)malloc(sizeof(char*) * numberOutputs);
       int counterOutput = numberInputs + numberOutputs;
       
       
       k = 0;
       while(k < numberOutputs)
       {
       		outputList[k] = (char*)malloc(sizeof(char) * 10);
       		fscanf(file, "%s", outputList[k]);
       		k++;
       }

       








       while(1)
       {
       		
       		if(fscanf(file, "%s", opTypeName) != 1)
       		{
       			break;
       		}
       
      gate type = setType(opTypeName);





      
      operation *oper = (operation*)malloc(sizeof(operation));
      (*oper).type = type;

      if(type != not)
      {
      	fscanf(file, "%s %s %s", inList1, inList2, outList);
      }
      else
      {
      	fscanf(file, "%s %s", inList1, outList);
      	(*oper).inputList2 = 0;
      }







      int temporaryIndexValue;
      for(i = 0; i < numberInputs; i++)
      {
      	if(strcmp(inputList[i],inList1) == 0)
      	{
      		temporaryIndexValue = i;
      		break;
      	}
      	temporaryIndexValue = -1;
      }
      int input1Index = temporaryIndexValue;

      if(input1Index < 0)
      {
      	(*oper).inputList1 = indexList(temp, inList1) + numberInputs + numberOutputs;
      }
      else
      {
      	(*oper).inputList1 = input1Index;
      }









      for(i = 0; i < numberInputs; i++)
      {
      	if(strcmp(inputList[i],inList2) == 0)
      	{
      		temporaryIndexValue = i;
      		break;
      	}
      	temporaryIndexValue = -1;
      }

      int input2Index = temporaryIndexValue;

      if(type != not)
      {
      	if(input2Index < 0)
      	{
      		(*oper).inputList2 = indexList(temp, inList2) + numberInputs + numberOutputs;
      	}
      	else
      	{
      		(*oper).inputList2 = input2Index;
      	}
      }










      for(i = 0; i < numberOutputs; i++)
      {
      	if(strcmp(outputList[i],outList) == 0)
      	{
      		temporaryIndexValue = i;
      		break;
      	}
      	temporaryIndexValue = -1;
      }
      int outputIndex = temporaryIndexValue;
     


      if(outputIndex >= 0)
      {
        (*oper).output = outputIndex + numberInputs;
      	
      }
      else
      {
      	char* outT = (char*)calloc(strlen(outList) + 1, sizeof(char));
        strcpy(outT, outList);
        temp = insert(outT, temp);
        (*oper).output = counterOutput++;
      }

      head = insert(oper, head);
    }







///END WHILE(1)








    int tempSize = 0;
    node* tempHead = temp;
    while(tempHead != NULL)
    {
    	tempSize++;
    	tempHead = (*tempHead).next;
    }

    int** result = malloc(sizeof(int*) * (1 << numberInputs));
   		
	for(i = 0; i < (1 << numberInputs); i++)
	{
		int *ins = (int*)malloc(sizeof(int) * numberInputs);
		for(k = 0; k < numberInputs; k++)
		{
			ins[numberInputs - k - 1] = 1 & (i >> k);
		}
		
		 			
			int rows = numberOutputs + numberInputs;
			int *arr = (int*) malloc(sizeof(int)*tempSize);
			int *curr = (int*) malloc(sizeof(int) * rows);
			int inputList1;
			int inputList2;

			int k = 0;
			while(k < numberInputs)
			{
				curr[k] = ins[k];
				k++;
			}

			node *currPtr = head;
			while(currPtr != NULL)
			{
				operation *oper = (operation*)(*currPtr).value;
				if((*oper).inputList1 < numberInputs)
				{
					inputList1 = ins[(*oper).inputList1];
				}
				else
				{
					inputList1 = arr[(*oper).inputList1 - numberInputs - numberOutputs];
				}


				if((*oper).inputList2 >= numberInputs)
				{
					inputList2 = arr[(*oper).inputList2 - numberInputs - numberOutputs];
				}
				else
				{
					inputList2 = ins[(*oper).inputList2];
				}


				int result = evaluate((*oper).type, inputList1, inputList2);
				if((*oper).output < rows && (*oper).output >= numberInputs)
				{
					curr[(*oper).output] = result;
				}
				else
				{
					arr[(*oper).output - rows] = result;
				}

				currPtr = (*currPtr).next;

			}
			free(arr);
			int *horiz = curr;

		
		free(ins);
		result[i] = horiz;

	}

	int** finalList = result;
    
       
    
    for(i = 0; i < (1 << numberInputs); i++)
    {
    	for(k = 0; k < numberInputs + numberOutputs; k++)
    	{
    		printf("%d ", finalList[i][k]);
    	}
    	printf("\n");
    }











//CLEAN UP
    fclose(file);


    for(k = 0; k < numberOutputs; k++)
    {
    	free(outputList[k]);
    }
    for(k = 0; k < numberInputs; k++)
    {
    	free(inputList[k]);
    }


    free(outputList);
    free(inputList);


    //freelistfull(head)
    if(head != NULL)
    {
	    node* tempHead1 = head;
	    while((*tempHead1).next != NULL)
	    {
	    	node* tempNext1 = (*tempHead1).next;
	    	free((*tempHead1).value);
	    	free(tempHead1);
	    	tempHead1 = tempNext1;
	    }

	    free((*tempHead1).value);
	    free(tempHead1);

	}


    //freelistfull(temp)
    if(temp != NULL)
    {
	    node* tempHead2 = temp;
	    while((*tempHead2).next != NULL)
	    {
	    	node* tempNext2 = (*tempHead2).next;
	    	free((*tempHead2).value);
	    	free(tempHead2);
	    	tempHead2 = tempNext2;
	    }

	    free((*tempHead2).value);
	    free(tempHead2);
	}

	for(k = 0; k < (1 << numberInputs); k++)
	{
		free(finalList[k]);
	}
	free(finalList);



	return 0;

}