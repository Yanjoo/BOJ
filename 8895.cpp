#include <bits/stdc++.h>

using namespace std;

// n개의 막대, 왼쪽에서 보이는 막대, 오른쪽에서 보이는 막대
// dp[n][l][r]
long long dp[21][21][21];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    int n, l, r;

    cin >> t;
    dp[1][1][1] = 1;

    for (int i=2; i<=20; i++) {
        for (int j=1; j<=20; j++) {
            for (int k=1; k<=20; k++) {
                dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1] + (i-2)*dp[i-1][j][k];
            }
        }
    }

    while (t--)
    {
        cin >> n >> l >> r;
        cout << dp[n][l][r] << '\n';
    }


    return 0;
}
