#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct tree {
    char data;
    struct tree *left, *right;
};
 int top = -1;
struct tree *stack[20];
struct tree *node;
 void push(struct tree* node) {
    stack[++top] = node;
}
 
struct tree * pop() {
    return (stack[top--]);
}
 
void inorder(struct tree *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%c", node->data);
        inorder(node->right);
    }
}
void preorder(struct tree *node) {
    if (node != NULL) {
        printf("%c", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(struct tree *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%c", node->data);
    }
}

 void operand(char b) {
    node = (struct tree*) malloc(sizeof(struct tree));
    node->data = b;
    node->left = NULL;
    node->right = NULL;
    push(node);
}
void operators(char a) {
    node = (struct tree*) malloc(sizeof(struct tree));
    node->data = a;
    node->right = pop();
    node->left = pop();
    push(node);
}
 
int main() {
    int i, p, k, ans;
    char s[20];
    printf("Enter the expression in postfix form \n");
    scanf("%s",s);
    k = strlen(s);
    i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        p= 2;
        else
        p=1;
        if (p == 1)
            operand(s[i]);
        else if (p == 2)
            operators(s[i]);
}
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack[top]);
    printf("\nThe preorder traversal of the tree is \n");
    preorder(stack[top]);
    printf("\nThe postorder traversal of the tree is \n");
    postorder(stack[top]);
    return 0;
}


