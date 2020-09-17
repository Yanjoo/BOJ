#include <bits/stdc++.h> 
using namespace std; 

int M, N;
int a[1002][1002];
bool visit[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool success;

void dfs(int i, int j)
{
    visit[i][j] = true;
    if (i == M-1) 
    {
        success = true;
        return;
    }

    for (int k=0; k<4; k++)
    {
        int nI = i + dx[k];
        int nJ = j + dy[k];

        if (!visit[nI][nJ] && !a[nI][nJ])
            dfs(nI, nJ);
    }
}

int main() 
{ 

    memset(a, 1, sizeof(a));

    scanf("%d %d", &M, &N);

    for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++)
            scanf("%1d", &a[i][j]);
        

    for (int i=1; i<=N; i++)
        if (!a[1][i] && !visit[1][i]) 
            dfs(1, i);
    
    if (success) printf("YES");
    else printf("NO");
  
    
    return 0; 
} 
