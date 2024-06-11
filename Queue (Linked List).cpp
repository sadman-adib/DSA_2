#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL;
struct node *rear = NULL;


void enqueue (int x) {
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear==NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}


void dequeue() {
    struct node *temp;
    temp = front;

    if(front==NULL) {
        cout << "Underflow" << endl;
    }
    else {
        cout << "Dequeue: " << front->data << endl;
        front = front->next;
        free(temp);
    }
}


void display() {
    struct node *temp;
    if(front==NULL) {
        cout << "Underflow" << endl;
    }
    else {
        temp = front;
        while(temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
    dequeue();
}



