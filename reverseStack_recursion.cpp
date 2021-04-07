#include<bits/stdc++.h>
using namespace std;

void pushintoStack(stack<int> &s,int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    pushintoStack(s,x);
    s.push(y);
}

void reverseStack(stack<int> &s) {
    if(s.empty()) return;
    int x = s.top();
    s.pop();
    reverseStack(s);
    pushintoStack(s,x);
}

int main() {
    stack<int> s,t;
    int n,x;
    cin >> n;
    while(n--) {
        cin >> x;
        s.push(x);
    }
    cout << "before reversing : " << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        t.push(s.top());
        s.pop();
    }
    cout << endl;
    while(!t.empty()) {
        s.push(t.top());
        t.pop();
    }
    reverseStack(s);
    cout << "After reversing: " << endl;
    while(!s.empty()) {
        cout << s.top() << " " ;
        s.pop();
    }
}