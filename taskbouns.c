#include <stdio.h>
#include <stdlib.h>
 
struct node
 {
    int data;
    struct node *next;
} *front, *back;
 
// To Create a queue 
void initialize() {
    front = back = NULL;
}
 
// To return queue size 
int getQueueSize() {
    int count = 0;
    struct node *temp = front;
     
    if(front == NULL && back == NULL)
        return 0;
 
    while(temp != back){
        count++;
        temp = temp->next;
    }
    if(temp == back)
        count++;
         
    return count;
}
 
int getFrontElement() {
    return front->data;
}
 
int getBackElement() {
    return back->data;
}
 

void isEmpty() {
    if (front == NULL && back == NULL)
        printf("empty queue\n");
    else
        printf("queue is not empty\n");
}
void enqueue(int num) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
     
    if (back == NULL) {
        front = back = temp;
    } else {
        back->next = temp;
        back = temp;
    }
}
 
void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("\nqueue is empty \n");
        return;
    } else {
        temp = front;
        front = front->next;
        if(front == NULL){
            back = NULL;
        }
        printf("removed element : %d\n", temp->data);
        free(temp);
    }
}
  
void printQueue() {
    struct node *temp = front;
  
    if ((front == NULL) && (back == NULL)) {
        printf("queue is empty\n");
        return;
    }
 
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL)
            printf("--> ");
            
    }
    printf("--> NULL");
}
 
int main() {
    initialize();
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    printQueue();
    printf("\n the size of the elements : %d\n", getQueueSize());
    printf("front element : %d\n", getFrontElement());
    printf("rear element : %d\n", getBackElement());
    // remove elements
    dequeue();
    dequeue();
    dequeue();
    dequeue();  
    
		
     
    return 0;
}

