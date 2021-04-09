#include<bits/stdc++.h>
using namespace std;

bool solve(string s) {
    int prevO = -1 , prevC = -1, currO , currC;
    stack<int> st;
    for(int i=0; s[i]!='\0' ;i++) {
        if(s[i]=='(') st.push(i);
        else if(s[i]==')') {
            currO = st.top();
            st.pop();
            currC = i;
            if(currC - currO == 2) return true;
            if(currC == prevC + 1 && currO == prevO - 1) return true;
            prevO = currO;
            prevC = currC;
        }
    }
    return false;
}

int main() {
    string s;
    getline(cin , s);
    if(solve(s)) cout << "Yes" << endl;
    else cout << "No" <<endl;
}