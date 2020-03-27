#include <iostream>
#include <stack>

using namespace std;

int n;
int a[100000];
stack<int> st;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        cin >> n;
        if (n == 0) break;
        long long max = 0;

        for (int i=0; i<n; i++) cin >> a[i];

        for (int i=0; i<n; i++) 
        {
            while (!st.empty() && a[i] < a[st.top()])
            {
                long long h = a[st.top()];
                st.pop();
                long long l = i;

                if(!st.empty()) l = i-st.top()-1;
                if (max < l*h) max = l*h;
            }
            st.push(i);
        }

        while (!st.empty())
        {
            long long h = a[st.top()];
            long long l = n;
            st.pop();
            if (!st.empty()) l = n-st.top()-1;
            if (max < l*h) max = l*h;
        }
        cout << max << '\n';
    }

    return 0;
}