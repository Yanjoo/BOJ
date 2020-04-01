#include <iostream>
#include <stack>

using namespace std;

int n, w, L;
int truck[1000];
stack<pair<int,int>> st;
bool start[1000];
int result;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> w >> L;
    
    for (int i=0; i<n; i++)
    {
        int weight;
        cin >> weight;
        if (st.empty())
            st.push({weight, 1});
        else
        {
            if (st.top().first + weight <= L && 
                st.top().second + 1 <= w)
            {
                weight += st.top().first;
                int num = st.top().second + 1;
                st.pop();
                st.push({weight, num});
            }
            else
            {
                st.push({weight, 1});
            }
        }
    }

    while (!st.empty())
    {
        result += w / st.top().second;
        st.pop();
    }

    cout << result + 1;


    return 0;
}