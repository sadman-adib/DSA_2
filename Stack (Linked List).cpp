#include<bits/stdc++.h>

struct node {
    int data;
    struct node* link;
} *top = NULL;


void push(int data) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow");
        exit(1);
    }

    newNode->data = data;
    newNode->link = top;

    top = newNode;
}


int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int data = top->data;
    struct node* temp;
    temp = top;
    top = top->link;
    free(temp);
    return data;
}


void print() {
    struct node* temp;
    temp = top;
    printf("The stack elements are: ");
    while(temp) {
        printf("%d", temp->data);
        temp = temp->link;
    }
}

int isEmpty() {
    return top == NULL;
}


int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

int main()
{
    push(1);
    push(2);
    push(3);
    pop();
    int data = peek();
    printf("%d",data);
}
