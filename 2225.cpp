#include <iostream>

using namespace std;

int dp[201][201];
int N, K;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    dp[0][0] = 1;

    for (int i=1; i<=K; i++)
    {
        for (int j=0; j<=N; j++)
        {
            for (int k=0; k<=j; k++)
            {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= 1000000000;
            }
        }
    }

    cout << dp[K][N];

    return 0;
}