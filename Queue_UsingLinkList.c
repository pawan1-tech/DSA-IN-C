
#include <stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;
int isempty(){
    if(front==NULL && rear==NULL)
        return 1;
    else
        return 0;
}
void enqueue(int val){
    struct queue *n1=(struct queue *)malloc(sizeof(struct queue));
    n1->data=val;
    n1->next=NULL;
    if(rear==NULL)
        front=rear=n1;
    else{
        rear->next=n1;
        rear=n1;
    }
}
void dequeue(){
    struct queue *temp;
    if(!isempty()){
        printf("\nThe dequeued value is %d",front->data);
        if(front==rear)
            front=rear=NULL;
        else{
            temp=front;
            front=front->next;
            free(temp);
        }
    }
}
void display(){
    struct queue *temp;
    if(!isempty()){
        temp=front;
        printf("\nThe elements of queue are....");
        while(temp!=NULL){
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    }
    else
        printf("\nQueue is empty");
}
int main(){
    enqueue(10);
    enqueue(5);
    enqueue(25);
    display();
    dequeue();
    display();
    return 0;
}


