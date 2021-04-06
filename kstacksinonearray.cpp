#include<bits/stdc++.h>
using namespace std;

void push(int x,int stackno,int &free,int next[],int arr[],int top[]) {
    if(free == -1) {
        cout << "Stack full" << endl;
        return;
    }
    arr[free] = x;
    int i = free;
    free = next[free];
    
    next[i] = top[stackno];
    top[stackno] = i;
} 

void pop(int stackno,int &free,int next[],int arr[],int top[]) {
    if(top[stackno] == -1) {
        cout << "Stack already empty" << endl;
        return;
    }
    int newfreed = top[stackno];
    top[stackno] = next[top[stackno]];
    next[newfreed] = free;
    free = newfreed;

    cout << "Popped element : " << arr[free] << endl;
}

int main() {
    int n,k,i;
    cin >> n >> k;
    int arr[n] , top[k] , next[n] , free;
    for(i=0; i < k;i++) top[i] = -1;
    free = 0;
    for(i=0; i< n; i++) next[i] = i+1;
    next[n-1] = -1;
    int choice , x, stackno;
    cout << "1 for push " << endl << "2 for pop " << endl << "3 to exit" << endl;
    while(1) {
        cin >> choice ;
        if(choice == 1) {
            cin >> x >> stackno ;
            push(x,stackno,free,next,arr,top);
        } else if(choice == 2) {
            cin >> stackno;
            pop(stackno,free,next,arr,top);
        } else exit(0);
    }
}