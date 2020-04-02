#include <iostream>

using namespace std;

int N;
char arr[65][65];
int z, o;

void check(int i, int j, int x, int y)
{
    for (int a=i; a<=x; a++)
    {
        for (int b=j; b<=y; b++)
        {
            if (arr[a][b] == '1') o++;
            else z++;
        }
    }
}

void solve(int i, int j, int size)
{
    if (size == 1)
    {
        cout << arr[i][j];
        return;
    }

    cout << "(";

    z = o = 0;
    check(i, j, i+size/2-1, j+size/2-1);
    if (z && o) solve(i, j, size/2);
    else cout << (o ? 1 : 0);

    z = o = 0;
    check(i, j+size/2, i+size/2-1, j+size/2+size/2-1);
    if (z && o) solve(i, j+size/2, size/2);
    else cout << (o ? 1 : 0);

    z = o = 0;
    check(i+size/2, j, i+size/2+size/2-1, j+size/2-1);
    if (z && o) solve(i+size/2, j, size/2);
    else cout << (o ? 1 : 0);

    z = o = 0;
    check(i+size/2, j+size/2, i+size/2+size/2-1, j+size/2+size/2-1);
    if (z && o) solve(i+size/2, j+size/2, size/2);
    else cout << (o ? 1 : 0);

    cout << ")";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
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