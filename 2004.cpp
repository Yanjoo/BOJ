#include <iostream>

using namespace std;

int n, m;

long long get(int a, int b)
{
    long long r = 0;
    long long d = b;
    while (a / d)
    {
        r += a / d;
        d *= b;
    }
    return r;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    int k = n - m;

    long long two = get(n, 2) - get(m, 2) - get(k, 2);
    long long five = get(n, 5) - get(m, 5) - get(k, 5);

    cout << (two < five ? two : five);

    return 0;
}