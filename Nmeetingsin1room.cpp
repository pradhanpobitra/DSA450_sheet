bool myway(const pair<int,int> &a,const pair<int,int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

class Solution
{
    public:
    // int getBest(map<int,int> &h,int v) {
    //     auto it = h.lower_bound(v);
    //     if(it == h.begin()) return 0;
    //     it--;
    //     return it->second;
    // }
    // void insert(map<int,int> &h,int v,int adv) {
    //     if(h[v] >= adv) return;
    //     h[v] = adv;
    //     auto it = h.lower_bound(v);
    //     it++;
    //     while(it!=h.end() && it->second <= adv) {
    //         auto it2 = it;
    //         it++;
    //         h.erase(it2);
    //     }
    // }
    
    
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back(make_pair(start[i],end[i]));
        sort(v.begin(),v.end(),myway);
        // map< int,int > h;
        // int mx = 1;
        // h[v[0].second] = 1;
        // for(int i=1; i < n; i++) {
        //     int adv = 1 + getBest(h, v[i].first);
        //     mx = max(mx , adv);
        //     insert(h,v[i].second,adv);
        // }
        // return mx;
        int prev = 0;
        int res = 1;
        for(int curr=1;curr< n ;curr++) {
            if(v[curr].first > v[prev].second) {
                res++;
                prev = curr;
            }
        }
        return res;
    }
};