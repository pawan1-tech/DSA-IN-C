
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void insertfirst(int val)
{
    struct node *n1= (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    n1->data=val;
    if(head==NULL)
    {
        n1->next=n1;
        head=n1;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        n1->next=head;
        head=n1;
        temp->next=n1;
    }
}
void display()
{
    struct node * temp;
    temp=head;
    printf("\n Elements in the list are...");
    do
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
void insertlast(int val)
{
    struct node *n1= (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    n1->data=val;
    if(head==NULL)
    {
        n1->next=n1;
        head=n1;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=n1;
        n1->next=head;
    }
}
void insertafter(int after, int val)
{
    struct node *n1= (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    n1->data=val;
    temp=head;
    do
    {
        if(temp->data==after)
        {
            n1->next=temp->next;
            temp->next=n1;
            return;
        }
        else
            temp=temp->next;
    }while(temp!=head);
    printf("\nSpecified element not found");
}
void search( int val)
{
    //struct node *n1= (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    //n1->data=val;
    temp=head;
    do
    {
        if(temp->data==val)
        {
            printf("\nElement found in the circular list");
            return;
        }
        else
            temp=temp->next;
    }while(temp!=head);
    printf("\nElement not found in the circular list");
}
/*void remov(int val)
{
    struct node *temp;
    struct node *last;
    struct node *before;
    //n1->data=val;
    temp=head;
    if(temp->data==val)
        {
            if(temp->next==head)
            {
                head=NULL;
                free(temp);
                return;
            }
            else 
            {
                last=head->next;
                while(last->next!=head)
                    last=last->next;
                head=temp->next;
                last->next=head;
                free(temp);
                return;
            }
        }
        else
        {
            temp=head->next;
            before=head;
            while(temp!=head)
            {
                if(temp->data==val)
                {
                    before->next=temp->next;
                    free(temp);
                    return;
                }
                else
                {
                    temp=temp->next;
                    before=before->next;
                }
            }
        }
   
}*/
void remov(int val)
{
    struct node*temp, *before, *last;
    temp=head;
    if(temp->data==val)
    {
        if(temp->next==head)
        {
            free(temp);
            head=NULL;
            return;
        }
        else
        {
            last=head->next;
            while(last->next!=head)
                last=last->next;
            head=head->next;
            last->next=head;
            free(temp);
            return;
        }
    }
    else
    {
        temp=head->next;
        before=head;
        while(temp!=head)
        {
            if(temp->data==val)
            {
               before->next=temp->next;
               free(temp);
               return;
            }
            else
            {
                temp=temp->next;
                before=before->next;
            }
        }
    }
}
int main()
{
    //printf("Hello World");
    insertfirst(10);
    insertfirst(20);
    display();
    insertafter(10,100);
   display();
    //search(200);
    remov(100);
    display();
    return 0;
}




