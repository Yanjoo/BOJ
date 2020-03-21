#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector<char> sequence;
stack<int> st;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    int val;
    int i = 1;

    while(n--)
    {
        cin >> val;
        if (st.empty())
        {
            do
            {
                st.push(i++);
                sequence.push_back('+');
            } while (st.top() != val);
        }

        if (st.top() < val)
        {
            while (st.top() != val) 
            {
                st.push(i++);
                sequence.push_back('+');
            }
        } 

        if (st.top() == val)
        {
            st.pop();
            sequence.push_back('-');
        }
        else 
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i=0; i<sequence.size(); i++) cout << sequence[i] << '\n';

    return 0;
}