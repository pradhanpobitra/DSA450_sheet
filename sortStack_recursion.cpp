#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int x) {
    if(s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insert(s,x);
    s.push(y);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty()) return;
   int x = s.top();
   s.pop();
   sort();
   insert(s,x);
}