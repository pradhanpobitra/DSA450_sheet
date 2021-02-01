#include<bits/stdc++.h>
using namespace std;
int matrix[1001][1001];
bool visited[1001][1001];
int n,m;
vector<int> clock(int cs,int dir) {
    vector<int> ans;
    int cells = n*m;
    int i,j;
    if(cs==0) i = j = 0;
    if(cs==1) i=0, j = m-1;
    if(cs==2) i=n-1,j=m-1;
    if(cs==3) i=n-1,j=0;
    while(cells) {
        if(j < 0) {
            i--;
            j=0;
            dir=2;
            continue;
        }
        if(i < 0) {
            i=0;
            j++;
            dir = 1;
            continue;
        }
        if(j >= m) {
            i++;
            j = m-1;
            dir = 0;
            continue;
        }
        if(i >= n) {
            i--;
            j--;
            dir = 3;
            continue;
        }
        if(visited[i][j]) {
            if(dir==2) i++,j++;
            else if(dir==3) i--,j++;
            else if(dir==1) i++,j--;
            else i--,j--;
            continue;
        }
        visited[i][j] = 1;
        ans.push_back(matrix[i][j]);
        cells--;
        if(dir==3) j--;
        else if(dir==2) i--;
        else if(dir==1) j++;
        else i++;
    }
    return ans;
} 
vector<int> anticlock(int cs,int dir) {
    vector<int> ans;
    int cells = n*m;
    int i,j;
    if(cs==0) i = j = 0;
    if(cs==1) i=0, j = m-1;
    if(cs==2) i=n-1,j=m-1;
    if(cs==3) i=n-1,j=0;
    while(cells) {
        if(j < 0) {
            i++;
            j=0;
            dir=0;
            continue;
        }
        if(i < 0) {
            i=0;
            j--;
            dir = 3;
            continue;
        }
        if(j >= m) {
            i--;
            j = m-1;
            dir = 2;
            continue;
        }
        if(i >= n) {
            i--;
            j++;
            dir = 1;
            continue;
        }
        if(visited[i][j]) {
            if(dir==2) i++,j--;
            else if(dir==3) i++,j++;
            else if(dir==1) i--,j--;
            else i--,j++;
            continue;
        }
        visited[i][j] = 1;
        ans.push_back(matrix[i][j]);
        cells--;
        if(dir==3) j--;
        else if(dir==2) i--;
        else if(dir==1) j++;
        else i++;
    }
    return ans;
}
int main() {
    int cs,cd,i,j;
    cin >> n >> m >> cs >> cd;
    
    memset(visited,false,sizeof visited);
    for(i=0;i<n;i++) for(j=0;j<m;j++) cin >> matrix[i][j];
    
    vector<int> st;
    if(cs==0) {
        if(cd==0) st = clock(cs,1);
        else st = anticlock(cs,0);
    }
    else if(cs==1) {
        if(cd==0) st = clock(cs,0);
        else st = anticlock(cs,3);
    }
    else if(cs==2) {
        if(cd==0) st = clock(cs,3);
        else st = anticlock(cs,2);
    }
    else {
        if(cd==0) st = clock(cs,2);
        else st = anticlock(cs,1);
    }
    int previous;
    if(st[0]==-1) previous = 0;
    else previous = -1;

    int mx = 0;
    if(st[0]==1) mx = 1;

    for(int i=1; i < (int) st.size() ; i++) {
        if(st[i]==-1) previous = i;
        else {
            mx = max(mx , i - previous);
        }
    }
    cout << mx << endl;
}