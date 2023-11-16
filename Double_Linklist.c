
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;
void insertfirst(int val)
{
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    n1->data=val;
    n1->prev=NULL;
    if(head==NULL)
    {
        head=n1;
        n1->next=NULL;
    }
    else
    {
        n1->next=head;
        head->prev=n1;
        head=n1;  
    }
}
void insertlast(int val)
{
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp=head;
    n1->data=val;
    n1->next=NULL;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n1;
    n1->prev=temp;
}
void display()
{
    struct node *temp;
    temp=head;
    printf("\n Elements of the list are...");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void insertafter(int after, int val)
{
   struct node *n1=(struct node *)malloc(sizeof(struct node));
   n1->data=val;
   struct node *temp, *aft;
   temp=head; 
   while(temp!=NULL)
   {
       if(temp->data==after)
       {
           aft=temp->next;
           temp->next=n1;
           n1->next=aft;
           aft->prev=n1;
           n1->prev=temp;
           return;
       }
       else
       {
           temp=temp->next;
       }
   }
   printf("\n Specified element not found");
}
void remov(int val)
{
    struct node *temp, *bef, *aft;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            if(temp->prev==NULL)
            {
                head=temp->next;
                (temp->next)->prev=NULL;
                free(temp);
                return;
            }
            else if (temp->next==NULL)
            {
                (temp->prev)->next=NULL;
                free(temp);
                return;
            }
            else
            {
                bef=temp->prev;
                aft=temp->next;
                bef->next=aft;
                aft->prev=bef;
            //(temp->prev)->next=temp->next;
            //(temp->next)->prev=temp->prev;
            free(temp);
            return;
            }
        }
        else
            temp=temp->next;
    }
}
void search(int val)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            printf("Element found in the list");
            return;
        }
        else
            temp=temp->next;
    }
    printf("\nElement not found");
}
int main()
{
    insertfirst(10);
    insertfirst(20);
    display();
    insertafter(20,100);
    display();
    remov(20);
    display();
    return 0;
}




