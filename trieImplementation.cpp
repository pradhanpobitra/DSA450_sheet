#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        TrieNode *children[26];
        TrieNode() {
            for(int i=0;i<26;i++) children[i] = nullptr;
        }
};

void insert(TrieNode *root,string s)
{
    for(char c : s) {
        if(root->children[c-'a']) root = root->children[c-'a'];
        else {
            root->children[c-'a'] = new TrieNode();
            root = root->children[c-'a'];
        }
    }
} 

void search(TrieNode *root,string s) {
    for(char c : s) {
        if(!root->children[c-'a']) {
            cout << s << " not found.";
            return;
        }
        root = root->children[c-'a'];
    }
    for(int i=0;i<26;i++) if(root->children[i]) {
        cout << s << " not found.";
        return;
    }
    cout << s << " found successfully" << endl;
}

int main() {
    int q,x;
    string s;
    cin >> q;
    TrieNode *root = new TrieNode();
    while(q--) {
        cin >> s;
        insert(root,s);
    }
    cin >> q;
    while(q--) {
        cin >> s;
        search(root,s);
        cout << endl;
    }
}