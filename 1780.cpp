#include <iostream>

using namespace std;

const int MAX = 3*3*3*3*3*3*3;

int N;
int arr[MAX][MAX];
int result[3];

bool check(int x, int y, int n)
{
    int v = arr[x][y];

    for (int i=x; i<x+n; i++)
    {
        for (int j=y; j<y+n; j++)
        {
            if (arr[i][j] != v)
                return false;
        }
    }

    return true;
}

void f(int x, int y, int n) 
{
   if (check(x, y, n))
   {
       result[arr[x][y]+1]++;
       return;
   }

   int m = n/3;
   for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            f(x + i*m, y + j*m, m);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> arr[i][j];

    f(0, 0, N);

    for (int i=0; i<3; i++)
        cout << result[i] << '\n';

    return 0;
}