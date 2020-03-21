#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int graph[300][300];
bool visit[300][300];
pair<int, int> direction[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int result;
vector<int> changes;

void dfs(int x, int y)
{
    visit[x][y] = true;

    for (int i=0; i<4; i++)
    {
        int next_x = x + direction[i].first;
        int next_y = y + direction[i].second;
        if (graph[next_x][next_y] > 0 && !visit[next_x][next_y]) 
            dfs(next_x, next_y);
    }
}

void count(int x, int y)
{
    int zeros = 0;
    for (int i=0; i<4; i++)
    {
        int next_x = x + direction[i].first;
        int next_y = y + direction[i].second;
        if (graph[next_x][next_y] <= 0)
            zeros++;
    }
    changes.push_back(zeros);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    int max = 0;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++) 
        {
            cin >> graph[i][j];
            if (max < graph[i][j]) 
                max = graph[i][j];
        }
    }

    int num;
    do
    {
        memset(visit, 0, sizeof(visit));
        num = 0;
        changes.clear();
        for (int i=1; i<N-1; i++)
        {
            for (int j=1; j<M-1; j++)
            {
                if (graph[i][j] > 0)
                    count(i, j);                    
            }
        }

        int index = 0;
        for (int i=1; i<N-1; i++)
        {
            for (int j=1; j<M-1; j++)
            {
                if (graph[i][j] > 0) 
                    graph[i][j] -= changes[index++];
            }
        }

        for (int i=1; i<N-1; i++)
        {
            for (int j=1; j<M-1; j++)
            {
                if (graph[i][j] > 0 && !visit[i][j]) 
                {
                    dfs(i, j);                  
                    num++;
                }
            }
        }

        result++;
        if (result >= max)
        {
            result = 0;
            break;
        }
    } while (num < 2);

    cout << result;

    return 0;
}