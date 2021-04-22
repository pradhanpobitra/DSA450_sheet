#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        TrieNode *children[26];
        bool isleaf;
        TrieNode() {
            for(int i=0;i<26;i++) children[i] = NULL;
            isleaf = false;
        }
        static void insert(TrieNode *root,string s) {
            for(char c : s) {
                if(!root->children[c-'a']) root->children[c-'a'] = new TrieNode();
                root = root->children[c-'a'];
            }
            root->isleaf = true;
        }
};

string shortestuniqueprefix(TrieNode *root,string s) {
    int lowestIndex = 0;
    root = root->children[s[0] - 'a'];
    for(int i=1;s[i]!='\0';i++) {
        int counts = 0;
        for(int j=0;j<26;j++) if(root->children[j]) counts++;
        if(counts > 1) lowestIndex = i;
        root = root->children[s[i]-'a'];
    }
    string ans;
    for(int i=0; i<= lowestIndex ; i++) ans.push_back(s[i]);
    return ans;
}

int main() {
    int n,i;
    cin >> n;
    string arr[n];
    for(i=0;i<n;i++) cin >> arr[i];
    TrieNode *root = new TrieNode();
    for(i=0;i<n;i++) TrieNode::insert(root,arr[i]);
    vector<string> v;
    for(i=0;i<n;i++) {
        v.push_back(shortestuniqueprefix(root,arr[i]));
    }
    for(string s : v) cout << s << " ";
    cout << endl;
}