#include<bits/stdc++.h>
using namespace std;

bool myway(const pair<int,int> &a,const pair<int,int> &b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int,int>> foregroundProcesses,backgroundProcesses;
    int n,m,u,v,threshold;
    cin >> n >> m >> threshold;
    for(int i=0;i<n;i++) {
        cin >> u >> v;
        foregroundProcesses.push_back(make_pair(u,v));
    }
    for(int i=0;i<m;i++) {
        cin >> u >> v;
        backgroundProcesses.push_back(make_pair(u,v));
    }
    sort(foregroundProcesses.begin(),foregroundProcesses.end(),myway);
    sort(backgroundProcesses.begin(),backgroundProcesses.end(),myway);

    int i = 0, j = m-1;
    int mxsum = INT_MIN;
    vector<pair<int,int>> final_list;

    while(i < n && j >= 0) {
        int sum = foregroundProcesses[i].second + backgroundProcesses[j].second;
        if(sum > threshold) j--;
        else {
            if(sum < mxsum) {
                i++;
                continue;
            }
            else if(sum > mxsum) {
                final_list.clear();
                mxsum = sum;
            }
            final_list.push_back(make_pair(foregroundProcesses[i].first,backgroundProcesses[j].first));
            int index = j-1;
            while(index >= 0 && backgroundProcesses[index].second == backgroundProcesses[j].second) {
                final_list.push_back(make_pair(foregroundProcesses[i].first,backgroundProcesses[index].first));
                index--;
            }
            i++;
        }
    }
    for(pair<int,int> process : final_list) {
        cout << process.first << " " << process.second << endl;
    }
}