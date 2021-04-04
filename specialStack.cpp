#include<iostream> 
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int x) : data(x) , next(0) , prev(0) {}
};

class SpecialStack{
    public:
        int size;
        Node *head, *mid;
        SpecialStack() {
            head = new Node(1);
            mid = head;
            size = 1;
        }
        void push(int x) {
            Node *t = new Node(x);
            t->next = head;
            head->prev = t;
            head = t;
            if(size % 2 == 0) {
                mid = mid->prev;
            }
            size++;
        }
        void pop() {
            if(size % 2) {
                mid = mid->next;
            }
            head = head->next;
            head->prev = NULL;
            delete head->prev;
            size--;
        }
        void getMiddle() {
            cout << mid->data << endl;
        }
        void deleteMiddle() {
            if(size % 2 ==0) {
                mid->prev->next = mid->next;
                mid->next->prev = mid->prev;
                mid = mid->prev;
            }
            else {
                mid->prev->next = mid->next;
                mid->next->prev = mid->prev;
                mid = mid->next;
            }
        }
};


int main() {
    SpecialStack st;
    st.push(2);
    st.push(3);
    // st.push(4);
    st.getMiddle();
}