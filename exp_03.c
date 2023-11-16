#include <stdio.h>
#include <stdlib.h>
struct stack{
    int data;
    struct stack *next;
} *top=NULL;

int isempty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(int val){
    struct stack *n1=(struct stack *)malloc(sizeof(struct stack));
    n1->data=val;
    n1->next=top;
    top=n1;
}

void pop(){
    struct stack *temp;
    if(!isempty()){
        printf("\n The poped value is %d",top->data);
        temp=top;
        top=top->next;
        free(temp);
    }
    else
        printf("\nUnderflow:Stack is empty");
}

void peek(){
    if(!isempty()){
        printf("\n The value at top is %d",top->data);   
    }
    else
        printf("\nStack is empty");
}

void display(){
    struct stack *temp;
    if(!isempty()){
        temp=top;
        printf("\nThe elements of stacck are...");
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
    else
        printf("\nEmpty stack");
}
int main(){
  
    push(101);
			   push(103);
    push(109);
    display();
    pop();
    return 0;
}
