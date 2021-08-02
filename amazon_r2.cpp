#include <bits/stdc++.h>
using namespace std;

string solve(string &s)
{
    int n = s.length();
    string output;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (st.empty())
            {
                if (i - 1 >= 0)
                {
                    if (s[i - 1] == '-')
                        st.push(1);
                    else
                        st.push(0);
                }
                else
                    st.push(0);
            }
            else
            {
                int x = st.top();
                if (i - 1 >= 0)
                {
                    if (s[i - 1] == '-')
                        st.push(1 + x);
                    else
                        st.push(x);
                }
                else
                    st.push(x);
            }
        }
        else if (s[i] == ')')
        {
            st.pop();
        }
        else if (s[i] == '+')
        {
            if (st.empty())
                output.push_back(s[i]);
            else
            {
                int x = st.top();
                if (x % 2)
                    output.push_back('-');
                else
                    output.push_back('+');
            }
        }
        else if (s[i] == '-')
        {
            if (st.empty())
                output.push_back('-');
            else
            {
                int x = st.top();
                if (x % 2)
                    output.push_back('+');
                else
                    output.push_back('-');
            }
        }
        else
        {
            output.push_back(s[i]);
        }
    }
    return output;
}
int main()
{
    string s;
    cin >> s;
    string op = solve(s);
    cout << op << endl;
}