#include<bits/stdc++.h>

using namespace std;

#define max 5
int Queue[max];

int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == max -1) {
        cout << "Overflow" << endl;
    }
    else if(front==-1 && rear==-1) {
        front = 0;
        rear = 0;
        Queue[rear] = x;
    }
    else {
        rear++;
        Queue[rear] = x;
    }
}


void dequeue() {
    if(front==-1 && rear==-1) {
        cout << "Underflow" << endl;
    }
    else if(front==rear) {
        front = -1;
        rear = -1;
    }
    else {
        cout << "Dequeue: " << Queue[front] << endl;
        front++;
    }
}


void display() {
    if(front==-1 && rear==-1) {
        cout << "Underflow" << endl;
    }
    else {
        for(int i=front;i<=rear;i++) {
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
}


int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    enqueue(4);
    enqueue(5);
    dequeue();
    display();


}
