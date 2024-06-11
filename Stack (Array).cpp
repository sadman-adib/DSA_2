#include<bits/stdc++.h>

#define MAX 3

int stack_arr[MAX];
int top = -1;


int isFull() {
    if(top == MAX-1)
        return 1;
    else
        return 0;
}


int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}


void push(int data){
    if(isFull()){
        printf("Stack overflow");
        return;
    }

    top = top + 1;
    stack_arr[top] = data;
}


int pop() {
    int value;
    if(isEmpty()) {
        printf("Stack underflow");
        exit(1);
    }

    value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek() {
    if(isEmpty()) {
        printf("Empty Stack");
        exit(1);
    }
    return stack_arr[top];
}


void display() {
    if(isEmpty()){
        printf("Empty Stack");
        return;
    }

    for(int i=0;i<=top;i++) {
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}


int main()
{
    int data;
    push(1);
    push(2);
    push(3);
    pop();
    data = peek();
    printf("%d ", data);
    display();
}
