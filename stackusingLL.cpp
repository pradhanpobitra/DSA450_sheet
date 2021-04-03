#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;
        node(int x) : data(x) , next(0) {}
};

class Stack{
    public:
        node *top;
        Stack() {
            top = 0;
        }
        void pop() {
            if(this->top==0) {
                cout << "Stack is empty!" <<endl;
            }
            else {
                node *t = this->top;
                this->top = this->top->next;
                delete t;
            }
        } 
        void peek() {
            if(this->top==0) cout << "Empty stack " <<endl;
            else cout << this->top->data << endl;
        }
        void push(int x) {
            node *t = new node(x);
            t->next = this->top;
            this->top = t;
        }
};

int main() {
    Stack s;
    s.push(5);
    s.peek();
    s.pop();
    s.pop();
    s.pop();
    s.peek();
}