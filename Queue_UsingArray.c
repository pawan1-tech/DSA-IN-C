
#include <stdio.h>
#define size 10
int queue[size];
int front=-1;
int rear=-1;
int isempty(){
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}
int isfull(){
    if(rear==size-1)
        return 1;
    else 
        return 0;
}
void enqueue(int val){
    if(!isfull()){
        rear=rear+1;
        queue[rear]=val;
        if(front==-1)
            front=rear;
    }
    else
        printf("Overflow:Queue is full");
}
void dequeue(){
    if(!isempty()){
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=front+1;
        }
    }
    else
        printf("\nUnderflow:Queue is empty");
}
void display(){
    int i;
    if(!isempty()){
        printf("\nThe elements of queue are....");
        for(i=front;i<=rear;i++){
            printf("\n%d",queue[i]);
        }
    }
    else
        printf("\nQueue is empty");
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(50);
    display();
    dequeue();
    display();
    return 0;
}


