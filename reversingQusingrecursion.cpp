#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int> &q) {
    if(q.empty()) return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}
int main() {
    int n,x;
    queue<int> q;
    cin >> n;
    while(n--) {
        cin >> x;
        q.push(x);
    }
    reverse(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}