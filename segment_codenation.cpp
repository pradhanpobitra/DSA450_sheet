#include<bits/stdc++.h>
using namespace std;

long long buildtree(vector<int> &v,vector<long long> &tree,int l,int r,int index) {
    if(l > r) return 0;
    if(l == r) {
        return tree[index] = v[l];
    }
    int mid = ( l + r ) / 2;
    long long left = buildtree(v,tree,l,mid,2*index+1);
    long long right = buildtree(v,tree,mid+1,r,2*index + 2);
    return tree[index] = left + right;
}

void update(vector<long long> &tree,int l,int r,int index,int ind,int val) {
    if(l > r) return;
    if(l == r)  {
        tree[index] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(ind <= mid) update(tree,l,mid,2*index+1,ind,val);
    else update(tree,mid+1,r,2*index+2,ind,val);
    tree[index] = tree[2*index+1] + tree[2*index+2];
}

long long query(vector<long long> &tree,int l,int r,int x,int y,int index) {
    if(l > r) return 0;
    if(x >= l && r <= y) return tree[index];
    else if(r < x || l > y) return 0;
    int mid = ( l + r ) / 2;
    long long ans = query(tree,l,mid,x,y,2*index+1) + query(tree,mid+1,r,x,y,2*index + 2);
    return ans;
}

#define M 1000000007
vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<int> odds,evens;
    for(int i=0;i<n;i++) {
        if(i%2) odds.push_back(A[i]);
        else evens.push_back(A[i]);
    }    
    int x = odds.size(), y = evens.size();
    vector<long long> tree(4*n + 5), tree_odd(4*x + 5), tree_even(4*y + 5);
    
    buildtree(odds,tree_odd,0,x-1,0);
    buildtree(evens,tree_even,0,y-1,0);
    buildtree(A,tree,0,n-1,0);
    
    vector<int> ans;
    for(auto xx : B) {
        int type = xx[0];
        int l = xx[1];
        int r = xx[2];
        if(type == 1) {
            l--;
            if(l % 2) {
                int i = (l - 1) / 2;
                update(tree_odd,0,x-1,0,i,r);
            }
            else {
                int i = l / 2;
                update(tree_even,0,y-1,0,i,r);
            }
            update(tree,0,n-1,0,l,r);
        }
        else {
            l--;
            r--;
            int range = (r -l + 1);
            int negatives = range / 2;
            
            if(l % 2) {
                int first_even = l + 1;
                first_even /= 2;
                int last_even = first_even + negatives - 1;
                long long sum = query(tree,0,n-1,l,r,0);
                if(negatives > 0) {
                    sum -= 2 * query(tree_even, 0, y-1, first_even,last_even,0);
                    sum = (sum + M) % M;
                }
                sum = (sum + M) % M;
                ans.push_back(sum);
            }
            else {
                int first_odd = l / 2;
                int last_odd = first_odd + negatives - 1;
                long long sum = query(tree,0,n-1,l,r,0);
                if(negatives > 0) {
                    sum -= 2 * query(tree_odd,0,x-1,first_odd,last_odd,0);
                    sum = (sum + M) % M;
                }
                sum = (sum + M) % M;
                ans.push_back(sum);
            }
        }
    }
    return ans;
}

int main() {
    int t,n,x,m;
    cin >> n >> m;
    vector<int> v;
    vector<vector<int>> q;
    while(n--) {
        cin >> x;
        v.push_back(x);
    }
    while(m--) {
        vector<int> a;
        cin >> t >> n >> x;
        a.push_back(t);
        a.push_back(n);
        a.push_back(x);
        q.push_back(a);
    }
    vector<int> ans = solve(v,q);
    for(int x : ans) cout << x << endl;
}