    void dfs(stack<int> &s,int i,vector<int> adj[],bool vis[]) {
        vis[i] = true;
        for(int x : adj[i]) {
            if(!vis[x]) dfs(s,x,adj,vis);
        }
        s.push(i);
    }

    void reverse(vector<int> adj[],int V) {
        vector<int> rev[V];
        for(int i=0;i<V;i++) {
            for(int x : adj[i]) rev[x].push_back(i);
        }
        for(int i=0;i<V;i++) adj[i].clear();
        for(int i=0;i<V;i++) {
            for(int x : rev[i]) adj[i].push_back(x);
        }
    }
    void dfs2(int i,vector<int> adj[],bool vis[]) {
        vis[i] = true;
        for(int x : adj[i]) {
            if(!vis[x]) dfs2(x,adj,vis);
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        //code here
        bool vis[V] = {0};
        stack<int> s;
        for(int i=0;i<V;i++) {
            if(!vis[i]) dfs(s,i,adj,vis);
        }
        reverse(adj,V);
        memset(vis,0,sizeof(vis));
        int count = 0;
        while(!s.empty()) {
            int x = s.top();
            s.pop();
            if(vis[x]) continue;
            dfs2(x,adj,vis);
            count++;
        }
        return count;
    }