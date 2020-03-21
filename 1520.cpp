#include <cstdio>
#include <iostream>

using namespace std;

int M, N;
int arr[502][502];
int dp[502][502];
pair<int, int> direction[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void dfs(int i, int j, int v)
{
    dp[i][j] += v;

    for (int k=0; k<4; k++)
    {
        int next_i = i + direction[k].first;
        int next_j = j + direction[k].second;
        int cur = arr[i][j];

        if (arr[next_i][next_j] < cur && arr[next_i][next_j]) 
            dfs(next_i, next_j, v);
    }
}

int main()
{
    scanf("%d %d", &M, &N);
    for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++)
            scanf("%d", &arr[i][j]);

    dfs(1, 1, 1);

    printf("%d", dp[M][N]);

    return 0;
}