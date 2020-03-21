#include <iostream>
#include <stack>
#include <string>

using namespace std;

string a, b;
bool erase[1000000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> a >> b;

    if (b.size() == 1)
    {
        for (int i=0; i<a.size(); i++)
        {
            if (a[i] == b[0]) erase[i] = true;
        }
    }
    else
    {
        stack<pair<int, int>> st;
        int match_len = 0;
        for (int i=0; i<a.size(); i++)
        {
            if (a[i] == b[match_len])
            {
                match_len++;
                st.push({i, match_len});
            }
            else if (a[i] == b[0])
            {
                match_len = 1;
                st.push({i, match_len});
            }
            else
            {
                match_len = 0;
                while (!st.empty()) st.pop();
            }
            
            if (match_len == b.size())
            {
                for (int j=0; j<match_len; j++)
                {
                    auto top = st.top();
                    st.pop();
                    erase[top.first] = true;
                }

                if (!st.empty()) match_len = st.top().second;
                else match_len = 0;
            }
        }
    }

    bool FRULA = true;

    for (int i=0; i<a.size(); i++)
    {
        if (!erase[i])
        {
            cout << a[i];
            FRULA = false;
        }
    }

    if (FRULA) cout << "FRULA";

    return 0;
}