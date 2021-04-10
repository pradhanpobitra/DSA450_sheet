#include<bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q) {
    int n = q.size();
    stack<int> s;
    int x = n / 2;
    while(x--) {
        s.push(q.front());
        q.pop();
    }
    x = n / 2;
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    while(x--) {
        q.push(q.front());
        q.pop();
    }
    x = n/2;
    while(x--)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    return;
}

int main() {
    int n,x;
    queue<int> q;
    cin >> n;
    while(n--) {
        cin >> x;
        q.push(x);
    }
    interleave(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}