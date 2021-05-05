bool solve(bool graph[101][101],int m,int vertex,int V,int color[]) {
    if(vertex == V) return true;
    bool available[m+1];
    for(int i=1;i<=m;i++) available[i] = 1;
    for(int i=0;i<V;i++) if(graph[vertex][i]) available[color[i]] = 0;
    for(int i=1;i<=m;i++) {
        if(available[i]) {
            color[vertex] = i;
            bool x = solve(graph,m,vertex+1,V,color);
            color[vertex] = 0;
            if(x) return true;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V] = {0};
    return solve(graph,m,0,V,color);
}