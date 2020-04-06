#include <iostream>

using namespace std;

const int MAX = 3*3*3*3*3*3*3;

char a[MAX][MAX];
int N;

void solve(int i, int j, int n, int state)
{
    int x, y;
    if (state)
    {
        for (x=i; x<i+n; x++)
            for (y=j; y<j+n; y++)
                a[x][y] = ' ';
    }
    else
    {
        if (n == 1) 
            a[i][j] = '*';
        else
        {
            int m = n/3;
            for (int x=0; x<3; x++)
            {
                for (int y=0; y<3; y++)
                {
                    if (x==1 && y==1) 
                        solve(i+m*x, j+m*y, m, 1);
                    else
                        solve(i+m*x, j+m*y, m, 0);
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    solve(0, 0, N, 0);

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << a[i][j];
        cout << '\n';
    }

    return 0;
}