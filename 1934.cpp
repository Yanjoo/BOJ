#include <iostream>

using namespace std;

int T;
int A, B;

int GCD(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;

    while (T--)
    {
        cin >> A >> B;
        int gcd = GCD(A, B);
        cout << A * B / gcd << '\n';
    }

    return 0;
}