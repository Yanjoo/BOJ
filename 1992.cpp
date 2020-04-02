#include <iostream>

using namespace std;

int N;
char arr[65][65];

bool check(int i, int j, int size)
{
    int o=0, z=0;
    for (int a=i; a<i+size; a++)
    {
        for (int b=j; b<j+size; b++)
        {
            if (arr[a][b] == '1') o++;
            else z++;
        }
    }

    if (o && z) return false;
    else return true;
}

void solve(int i, int j, int size)
{
    if (check(i, j, size)) cout << arr[i][j];
    else
    {
        cout << "(";
        int n = size/2;
        for (int x=0; x<2; x++)
            for (int y=0; y<2; y++)
                solve(i+n*x, j+n*y, n);
        cout << ")";
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int o=0, z=0;

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '1') o++;
            else z++;
        }
    }

    if (z && o) solve(1, 1, N);
    else cout << (o ? 1 : 0);
    return 0;
}