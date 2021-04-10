#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *prev,*next;
        Node(int x) {
            data = x;
            prev = next = 0;
        }
};
class LRUCache
{
private:
    int max_size,curr_size;
    unordered_map<int,Node*> h;
    Node *head, *tail;
public:
    // constructor for cache
    LRUCache(int cap)
    {
        // Intialize the cache capacity with the given
        // cap
        max_size = cap;
        curr_size = 0;
        head = tail = NULL;
    }
    
    // this function should return value corresponding to key
    int get(int key)
    {
        // your code here
        if(h[key] == 0 || h[key]->data == -1) return -1;
        if(h[key] == head) return head->data;
        else if(h[key] == tail) {
            Node *t = tail;
            tail = tail->prev;
            tail->next = NULL;
            t->prev = NULL;
            t->next = head;
            head->prev = t;
            head = t;
            return head->data;
        } else {
            Node *t = h[key];
            t->prev->next = t->next;
            t->next->prev = t->prev;
            t->next = head;
            t->prev = NULL;
            head->prev = t;
            head = t;
            return head->data;
        }
        
    }
    
    // storing key, value pair
    void set(int key, int value)
    {
        // your code here
        if(h[key] && h[key]->data != -1) {
            h[key]->data = value;
            if(h[key] == head) return;
            else if(h[key] == tail) {
                tail->prev->next = 0;
                Node *t = tail;
                tail = tail->prev;
                t->prev = 0;
                t->next = head;
                head->prev = t;
                head = t;
            }
            else {
                Node *t = h[key];
                t->prev->next = t->next;
                t->next->prev = t->prev;
                t->prev = 0;
                t->next = head;
                head->prev = t;
                head = t;
            }
        } else {
            if(curr_size == max_size) {
                Node *t = new Node(value);
                t->next = head;
                head->prev = t;
                head = t;
                tail->prev->next = 0;
                t = tail;
                t->data = -1;
                tail = tail->prev;
                // delete t;
                h[key] = head;
            } else {
                curr_size++;
                Node *t = new Node(value);
                t->next = head;
                if(head==0) {
                    head = tail = t;
                }
                else {
                    head->prev = t;
                    head = t;
                }
                h[key] = head;
            }
        }
    }
};