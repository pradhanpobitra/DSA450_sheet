#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define mp make_pair
    int diff(string &a, string &b)
    {
        int c = 0;
        int i = 0;
        while (a[i] != '\0' && b[i] != '\0')
        {
            if (a[i] != b[i])
                c++;
            i++;
        }
        while (a[i] != '\0')
        {
            c++;
            i++;
        }
        while (b[i] != '\0')
        {
            c++;
            i++;
        }
        return c;
    }
    int ladderLength(string &beginWord, string &endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        bool h[n];
        memset(h, false, sizeof h);
        queue<pair<string, int>> q;
        q.push(mp(beginWord, 0));
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (p.first == endWord)
                return p.second + 1;
            for (int i = 0; i < n; i++)
            {
                if (h[i] == false && diff(p.first, wordList[i]) == 1)
                {
                    h[i] = true;
                    q.push(mp(wordList[i], p.second + 1));
                }
            }
        }
        return 0;
    }
};