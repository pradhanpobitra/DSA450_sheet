/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int> edges[],bool vis[],int startTime[],int endTime[],int &times) {
  vis[i] = true;
  startTime[i] = times;
  times++;
  for(int x : edges[i]) {
    if(!vis[x]) dfs(x,edges,vis,startTime,endTime,times);
  }
  endTime[i] = times;
  times++;
}

int main() {
  int n,a,b,q,x,y;
  scanf("%d",&n);
  vector<int> edges[n+1];
  int m = n-1;
  while(m--) {
    scanf("%d %d",&a,&b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int startTime[n+1] , endTime[n+1];
  bool vis[n+1] = {0};
  int times = 1;
  dfs(1,edges,vis,startTime,endTime,times);
  scanf("%d",&q);
  while(q--) {
    scanf("%d %d %d",&a,&x,&y);
    if(a==0) {
      if(startTime[x] < startTime[y] && endTime[x] > endTime[y]) printf("YES\n");
      else printf("NO\n");
    }
    else {
      if(startTime[y] < startTime[x] && endTime[y] > endTime[x]) printf("YES\n");
      else printf("NO\n");
    }
  }
}