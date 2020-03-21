#include <iostream>

using namespace std;

int T;

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }   
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;

    int M, N, x, y;
    while (T--)
    {
        cin >> M >> N >> x >> y;
        int result = x;
        int max = lcm(M, N);
        int t;
        do
        {
            t = (result - 1) % N + 1;
            if (t == y) break;
            result += M;
        } while (result <= max);
        cout << (result < max ? result : -1) << '\n';
    }

    return 0;
}