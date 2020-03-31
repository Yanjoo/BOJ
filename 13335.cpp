#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
int truck[1000];
queue<pair<int,int>> q;
bool start[1000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> w >> L;
    for (int i=0, k; i<n; i++)
    {
        cin >> k;
        q.push({k,i});
    }

    while (!q.empty())
    {
        auto cur = q.front();
        
        if(L - cur.first >= 0 && !start[cur.second])
        {
            L = L - cur.first;
            q.pop();
        }

    }


    return 0;
}