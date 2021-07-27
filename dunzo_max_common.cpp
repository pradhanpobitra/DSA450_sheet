#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<vector<int>>> &company,int i,vector<bool>& vis,int &top1,int &top2,int comp_no,int &group_size) {
    group_size++;
    vis[i] = true;
    if(i > top1) {
        top2 = top1;
        top1 = i;
    }
    else if(i > top2) top2 = i;

    for(int x : company[comp_no][i]) {
        if(!vis[x]) dfs(company,x,vis,top1,top2,comp_no,group_size);
    }

}

int countCompanies(int friends_nodes,vector<int> &friends_from,vector<int> &friends_to,vector<int> &friends_weight) {

    vector< vector<vector<int>> > company(101, vector<vector<int>> (friends_nodes+1 , vector<int> ()));

    for(int i=0; i < friends_from.size() ; i++) {

        company[friends_weight[i]][friends_from[i]].push_back(friends_to[i]);
        company[friends_weight[i]][friends_to[i]].push_back(friends_from[i]);
    }

    int mxproduct = 0;
    int mxgrpsize = 0;
    for(int j=1;j<=100;j++) {

        vector<bool> vis(friends_nodes+1, false);
        
        for(int i = 1; i<= friends_nodes ; i++) {
            if(!vis[i]) {
                int group_size = 0;
                int top1 = 0, top2 = 0;
                dfs(company,i,vis,top1,top2,j,group_size);
                if(group_size >= 2 && group_size > mxgrpsize)
                  mxproduct = top1 * top2;   
                else if(group_size == mxgrpsize) mxproduct = max(mxproduct , top1 * top2);  
                mxgrpsize = max(mxgrpsize , group_size);           
            }
        }

    }
    return mxproduct;
}

int main() {
    int fn , n;
    cin >> fn >> n;
    vector<int> ff,ft,fw;
    int x,y,z;
    while(n--) {
        cin >> x >> y >> z;
        ff.push_back(x);
        ft.push_back(y);
        fw.push_back(z); 
    }
    cout << countCompanies(fn,ff,ft,fw) << endl;
}