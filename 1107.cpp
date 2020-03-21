#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int M;
bool breakdown[10];
int num;

bool get(int n)
{
    if (n == 0) return breakdown[0];

    while (n)
    {
        if (breakdown[n % 10]) return true;
        n /= 10;
    }
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i=0, n; i<M; i++)
    {
        cin >> n;
        breakdown[n] = true;
    }

    if (M == 10)
    {
        cout << N - 100;
        return 0;
    }

    int t = N, size = 0;
    while (t)
    {
        t /= 10;
        size++;
    }

    int a = N-1;
    while(get(a)) a--;
    a = size + N - a;

    int b = N+1;
    while (get(b)) b++;
    b = size + b - N;

    int c = abs(N - 100);

    cout << min(a, min(b, c));

    return 0;
}