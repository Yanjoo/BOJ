#include <iostream>
#include <algorithm>

using namespace std;

int N;
int W[10][10];
int d[10];
int result = 987654321;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                cin >> W[i][j];

    for (int i=0; i<N; i++)
        d[i] = i;

    do
    {
        int sum = 0;
        bool ok = true;
        for (int i=0; i<N-1; i++)
        {
            if (W[d[i]][d[i+1]])
                sum += W[d[i]][d[i+1]];
            else
                ok = false;
        }

        if (W[d[N-1]][d[0]])
            sum += W[d[N-1]][d[0]];
        else
            ok = false;

        if (ok && result > sum)
            result = sum;
    } while (next_permutation(d+1, d+N));

    cout << result;

    return 0;
}
