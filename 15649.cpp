#include <iostream>

using namespace std;

int N, M;
bool visit[9];
int arr[9];

void solve(int cnt)
{
    if (cnt == M)
    {
        for (int i=0; i<M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i=1; i<=N; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            arr[cnt] = i;
            solve(cnt+1);
            visit[i] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    solve(0);

    return 0;
}