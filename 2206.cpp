#include <iostream>
#include <cstring>

using namespace std;

int graph[102][102];
bool visit[102][102];
int N;
int result = 1;
pair<int, int> direction[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void dfs(int i, int j)
{
    visit[i][j] = true;

    for (int x=0; x<4; x++)
    {
        int next_i = i + direction[x].first;
        int next_j = j + direction[x].second;

        if (graph[next_i][next_j] > 0 && !visit[next_i][next_j]) 
            dfs(next_i, next_j);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    int max = 0;
    int t;

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> t;
            graph[i][j] = t - 1;
            if (max < t) max = t;
        }
    }

    int range;
    while (max--)
    {
        range = 0;
        memset(visit, false, sizeof(visit));
        for (int i=1; i<=N; i++)
        {
            for (int j=1; j<=N; j++)
            {
                if (graph[i][j] > 0 && !visit[i][j])
                { 
                    dfs(i, j);
                    range++;
                }
                graph[i][j]--;
            }
        }
        if (result < range) result = range;
    }

    cout << result;

    return 0;
}