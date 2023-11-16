#include <stdio.h>
#define size 10
int stack[size];
int top=-1;

int isempty(){
    if(top==-1)
        return 1;
    else 
        return 0;
}

int isfull(){
    if(top==size-1)
        return 1;
    return 0;
}

void push(int val){
    if(!isfull()){
        top=top+1;
        stack[top]=val;
    }
    else
        printf("\nStack Overflow: Insertion not possible");
}

void pop(){
    if(!isempty()){
        printf("\nThe  poped value is %d",stack[top]);
        top--;
    }
    else
        printf("\nStack Underflow: Deletion not possible");
}

void peep(){
    if(!isempty()){
        printf("\nThe element at top is %d",stack[top]);
    }
    else
        printf("\nStack is empty");
}


void display(){
    int i;
    if(!isempty()){
        printf("\n The elements of stack are....");
        for(i=0;i<=top;i++){
            printf("%d\t",stack[i]);
        }
    }
    else
        printf("\nStack is empty");    
}

int main(){
    push(99);
    push(73);
    push(48);
    display();
    pop();
    display();
    peep();
    return 0;
}
