#include <stdio.h>
#include <stdlib.h>

struct cube{
    int data;
    struct cube *next;
} *head = NULL;

void insertFirst(int val){
    struct cube *n1 = (struct cube *)malloc(sizeof(struct cube));
    n1->data = val;
    n1->next = head;
    head = n1;
}

void insertLast(int val){
    struct cube *n1 = (struct cube *)malloc(sizeof(struct cube));
    struct cube *temp;
    n1->data = val;
    n1->next = NULL;
    if (head == NULL){
        head = n1;
        return;
    }
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n1;
}

void insertAfter(int val, int aft){
    struct cube *n1 = (struct cube *)malloc(sizeof(struct cube));
    struct cube *temp;
    n1->data = val;
    temp = head;
    while (temp != NULL){
        if (temp->data == aft){
            n1->next = temp->next;
            temp->next = n1;
            return;
        }else
            temp = temp->next;
    }
    printf("\nSpecified element not found");
}

int max(){
    struct cube *temp = head;
    int max = head->data;
    while (temp != NULL){
        if (temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void deleteMax(){
    int val = max();
    struct cube *temp, *before;
    if (head->data == val){
        head = head->next;
    }
    else{
        temp = head->next;
        before = head;
        while (temp != NULL){
            if (temp->data == val){
                before->next = temp->next;
                free(temp);
                return;
            }
            else{
                before = temp;
                temp = temp->next;
            }
        }
        printf("\nElement cannot be deleted");
    }
}

void sortList(){
    struct cube *current, *nextNode;
    int temp;

    current = head;
    while (current != NULL){
        nextNode = current->next;
        while (nextNode != NULL){
            if (current->data > nextNode->data){
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

void display(){
    struct cube *current = head;
    while (current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, val, after;
    printf("\nMenu:\n1.Insert Element at the Start of list.\n2.Insert Element at the End of list.\n3.Insert Element After which we have to add a new element.\n4.Delete the maximum element from the list\n5.Arrange the list in a sorted order.\n6.Display List.\n7.Exit.\n\n");
    do{
        printf("Enter Your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter the element to add First: ");
            scanf("%d", &val);
            insertFirst(val);
            break;

        case 2:
            printf("Enter the element to add Last: ");
            scanf("%d", &val);
            insertLast(val);
            break;

        case 3:
            printf("Enter the element to add After: ");
            scanf("%d", &val);
            printf("Enter the element After which we have to add the new element: ");
            scanf("%d", &after);
            insertAfter(val, after);
            break;

        case 4:
            printf("List before deleting the maximum element:\n");
            display();
            deleteMax();
            printf("List after deleting the maximum element:\n");
            display();
            break;

        case 5:
            printf("Original List:\n");
            display();
            sortList();
            printf("Sorted List:\n");
            display();
            break;

        case 6:
            display();
            break;

        default:
            exit(0);
        }
    } while (1);
    return 0;
}
