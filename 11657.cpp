#include <iostream>
#include <vector>
 
using namespace std;
 
const int INF = 987654321;
 
vector<pair<int, int>> edge[501];
int N, M;
int A, B, C;
long long d[501];
bool isNegative;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> N >> M;
    for (int i=0; i<M; i++)
    {
        cin >> A >> B >> C;
        edge[A].push_back({B, C});
    }
 
    for (int i=2; i<=N; i++) d[i] = INF;
 
    for (int i=1; i<=N; i++)
    {
        for (int u=1; u<=N; u++)
        {
            for (auto cur : edge[u])
            {
                int v = cur.first;
                int w = cur.second;
 
                if (d[u] != INF && d[v] > d[u] + w) 
                {
                    d[v] = d[u] + w;
                    if (i == N) isNegative = true;
                }
            }
        }
    }
 
    if (isNegative) cout << -1 << '\n';
    else
    {
        for (int i=2; i<=N; i++)
        {
            if (d[i] == INF) cout << -1 << '\n';
            else cout << d[i] << '\n';
        }
    }
    
    return 0;
}
