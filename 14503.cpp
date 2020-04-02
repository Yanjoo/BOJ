#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int r, c, d;
int graph[52][52];
bool visit[52][52];
int result;

pair<int, int> go[4] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
pair<int, int> back[4] = {{1,0}, {0,-1}, {-1,0}, {0,1}};

int get()
{
    if (d - 1 < 0) return 3;
    else return d-1;
}

void dfs(int x, int y)
{
    if (!visit[x][y])
    {
        visit[x][y] = true;
        result++;
    }

    for (int i=0; i<4; i++)
    {
        int next_x = x+go[d].first;
        int next_y = y+go[d].second;
        d = get();
        if (!visit[next_x][next_y] && !graph[next_x][next_y])
        {
            dfs(next_x, next_y);
            return;
        }
    }

    if (graph[x+back[d].first][y+back[d].second]) return;
    else dfs(x+back[d].first, y+back[d].second);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    memset(graph, 1, sizeof(graph));

    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            cin >> graph[i][j];
    
    dfs(r+1, c+1);
    cout << result;
    return 0;
}