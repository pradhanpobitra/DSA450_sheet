#include<bits/stdc++.h>
using namespace std;

class Queue {
    public:
        int *arr;
        int front,rear;
        int size;
        Queue(int size) {
            arr = new int[size];
            this->size = size;
            front = rear = 0;
        }
        bool isfull() {
            if((rear + 1) % size == front) return true;
            return false;
        }
        void enqueue(int x) {
            if(isfull()) {
                cout << "Cant insert " << x << ". Queue already full !" << endl;
            }
            else {
                arr[rear++] = x; 
                rear %= size;
            }
        }
        bool isempty() {
            if(rear==front) return true;
            return false;
        }
        void dequeue() {
            if(isempty()) {
                cout << "Queue already empty! No item to dequeue!" << endl;
            } 
            else {
                cout << "Popped element " << arr[front++] << endl;
                front %= size;
            }
        }
        void viewQueue() {
            int it = front;
            while(it != rear) {
                cout << arr[it] << " ";
                it++;
                it = it % size;
            }
        }
        ~Queue() {
            delete arr;
        }
};

int main() {
    int size;
    cout << "Enter the size of the queue : ";
    cin >> size;
    size++;
    Queue q(size);
    int choice,element;
    while(1) {
        cout << "press 1 to enqueue " << endl << " press 2 to dequeue " << endl << " press 3 to view the queue " << endl << " press 4 to exit the app" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << " Enter the element to enqueue " << endl;
                cin >> element;
                q.enqueue(element);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.viewQueue();
                break;
            case 4:
                exit(0);
        }
    }
}