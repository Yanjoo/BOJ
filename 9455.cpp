#include <bits/stdc++.h> 
using namespace std; 

int T;
int m, n;
int a[100][100];

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 

    cin >> T;
    while (T--)
    {
        memset(a, 0, sizeof(a));

        cin >> m >> n;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                cin >> a[i][j];

        int result = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=m-1; j>=0; j--)
            {
                if (a[j][i])
                {
                    int cur = j;
                    int cnt = 0;
                    while (cur < m-1 && !a[cur+1][i])
                    {
                        cur++;
                        cnt++;
                    }
                    result += cnt;
                    a[j][i] = 0;
                    a[cur][i] = 1;
                }
            }
        }

        cout << result << '\n';
        
    }
  
    return 0; 
} 
