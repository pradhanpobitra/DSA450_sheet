#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        char data;
        Node *prev,*next;
        Node(char x) {
            data = x, prev = next = 0;
        }
};

void solve(string &s) {
    int freq[26] = {0};
    Node *ptr[26] = {0};
    Node *head = 0, *tail = 0;
    for(char c : s) {
        freq[c - 'a']++;
        if(freq[c - 'a'] == 1) {
            if(head) {
                tail->next = new Node(c);
                tail->next->prev = tail;
                tail = tail->next;
            }
            else {
                head = tail = new Node(c);
            }
            ptr[c - 'a'] = tail;
        }
        else if(freq[c - 'a'] == 2) {
            Node *t = ptr[c-'a'];
            if(head == tail) {
                delete head;
                head = tail = 0;
            }
            else if(t == head) {
                head->next->prev = 0;
                head = head->next;
                delete t;
            }
            else if(t == tail) {
                t->prev->next = 0;
                tail = tail->prev;
                delete t;
            }
            else {
                t->prev->next = t->next;
                t->next->prev = t->prev;
                delete t;
            }
        }

        if(!head) cout << "#";
        else cout << head->data;
    }
}


int main() {
    string s;
    cin >> s;
    solve(s);
}