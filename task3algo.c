// https://github.com/satio7283/task3_algorithm.git
#include <stdio.h>
#include <stdlib.h>
struct Node
{
   int data;
   struct Node *next;
}

*front = NULL,*rear = NULL;

void insert(int value)
{
   struct Node *newNode;
   newNode = (struct Node*) malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("Insertion is Successfully implemented.\n");
}

void delete_func()
{
   if(front == NULL)
      printf("list already Empty.\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}

void display()
{
   if(front == NULL)
      printf("list already Empty.\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d - ",temp->data);
	 temp = temp -> next;
      }
      printf("%d - NULL\n",temp->data);
   }
}

int main()
{
   int choice, value;
   while(1){
      printf("enter your choice in the following menu :- \n");
      printf("[1] insert items \n");
      printf("[2] delete items \n");
      printf("[3] display items \n");
      printf("[4] exit the program \n");
      printf("enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: 
	 	printf("\nenter the value you want to be inserted: \n");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: 
		 delete_func();
	 	break;
	 case 3: 
	 	display(); 
	 	break;
	 case 4:
	 	return 0;
	 default: 
	 	printf("not availbale insertion,, Please try again\n");
      }
   }
}



