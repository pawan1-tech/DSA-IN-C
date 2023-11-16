#include <stdio.h>
#include <stdlib.h>
struct cube
{
    int data;
    struct cube* next;
} *head = NULL;
void insertfirst(int val)
{
    struct cube* n1 = (struct cube*)malloc(sizeof(struct cube));

    n1->data = val;

    n1->next = head;

    head = n1;
}
void insertlast(int val)
{
    struct cube *n1 = (struct cube *)malloc(sizeof(struct cube*));
    struct cube *temp;
    n1->data = val;
    n1->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n1;
}
// void insertafter()
void insertafer(int val ,int aft){
    struct cube *n1 = (struct cube *)malloc(sizeof(struct cube*));
    struct cube *temp;
    n1->data = val;
    temp=head;
   while(temp!=NULL)
   {
       if(temp->data==aft)
       {
           n1->next=temp->next;
           temp->next=n1;
           return;
       }
       else
            temp=temp->next;
   }
    printf("\nSpecified element not found");

}
void delet(int val){
    struct cube *temp,*before;
    if(head->data==val){
        head=head->next;    
    }
    else{
        temp=head->next;
        before=head;
        while(temp!=NULL){
            if(temp->data==val){
                before->next=temp->next;
                free(temp);
                return;
            }
            else{
                before=temp;
                temp=temp->next;
                //before=before->next;
            }
        }
        printf("\nElement cannot be deleted");
    }
}

    
void display(){
    struct cube *temp;

    temp = head;

    printf("\nThe elements are....");

    while (temp != NULL){
        printf("%d->", temp->data);

        temp = temp->next;
    }
}
struct node *reverse_list(struct node *head) {
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
int count(){
    int count=0;
    struct temp
    {
        /* data */
    };
    
}
int main()
{
    insertfirst(20); 
    insertfirst(21);
    insertfirst(22);
    insertfirst(23);
    insertfirst(24);
    display();
    delet(22);
    display();

    return 0;
}

