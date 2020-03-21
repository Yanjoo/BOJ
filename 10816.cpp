#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int a[500000];
int b[500000];

int search(int from, int to, int val)
{
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (a[mid] == val) return mid;
        else if (a[mid] < val) from = mid + 1;
        else to = mid - 1;
    }
    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];

    sort(a, a+N);

    cin >> M;
    for (int i=0, n; i<M; i++)
    {
        cin >> n;
        int t = search(0, N-1, n);
        if (t != -1)
        {
            int result = 1;
            int up = t + 1;
            while (a[up++] == n) result++;
            int down = t - 1;
            while (a[down--] == n) result++;
            cout << result << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }

    return 0;
}