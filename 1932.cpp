#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][502];
int n;
int result;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=i; j++)
            cin >> dp[i][j];

    for (int i=2; i<=n; i++)
        for (int j=1; j<=i; j++)
            dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
        
    for (int i=1; i<=n; i++)
        result = max(result, dp[n][i]);

    cout << result;

    return 0;
}