queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    stack<int> s;
    queue<int> qr;
    int l = q.size() - k;
    while(k--) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    while(l--) {
        q.push(q.front());
        q.pop();
    }
    while(!q.empty()) {
        qr.push(q.front());
        q.pop();
    }
    return qr;
}