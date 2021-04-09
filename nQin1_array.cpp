#include<bits/stdc++.h>
using namespace std;

class nQinArray {
    public:
        int n,k;
        int *arr, *front, *rear, *next, free;
        nQinArray(int n,int k) {
            this->n = n;
            this->k = k;
            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];
            free = 0;
            for(int i=0;i<n;i++) next[i] = i+1;
            next[n-1] = -1;
            for(int i=0;i<k;i++) front[i] = rear[i] = -1;
            cout << "Give the input array :" << endl;
            for(int i=0;i<n;i++) cin >> arr[i];
        } 
        void enqueue(int x,int qn){
            if(qn >= k) {
                cout << "invalid queue" << endl;
                return;
            }
            else {
                if(free == -1) {
                    cout << "Queue already full !" << endl;
                    return;
                }
                int space = free;
                free = next[free];
                arr[space] = x;
                if(front[qn]==-1) {
                    front[qn] = space;
                    rear[qn] = space;
                    next[rear[qn]] = -1;
                }
                else {
                    next[rear[qn]] = space;
                    rear[qn] = space;
                    next[rear[qn]] = -1;
                }
            }
        }
        int dequeue(int qn) {
            if(qn >= k) {
                cout << "Invalid queue number" << endl;
                return -1;
            }
            if(front[qn]==-1) return -1;
            int ans = arr[front[qn]];
            if(front[qn] == rear[qn]) {
                next[rear[qn]] = free;
                free = rear[qn];
                front[qn] = rear[qn] = -1;
            }
            else {
                int newfree = front[qn];
                front[qn] = next[front[qn]];
                next[newfree] = free;
                free = newfree;
            }
            return ans;
        }
};

int main() {
    int n,k;
    int choice , x , qn;
    cin >> n >> k;
    nQinArray Q(n,k);
    while(1) {
        cout << "1 to enqueue" << endl << "2 to dequeue" << "3 to exit" << endl;
        cin >> choice;
        if(choice == 1) {
            cin >> qn >> x;
            Q.enqueue(x,qn);
        }
        else if(choice == 2) {
            cin >> qn;
            cout << Q.dequeue(qn) << endl;
        } else exit(0);
    }
}