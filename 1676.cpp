#include <iostream>

using namespace std;

int N;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    int a = 0, b = 0;
    for (int i=2; i<=N; i++)
    {
        int t = i;
        while (t % 2 == 0)
        {
            a++;
            t /= 2;
        }
        while (t % 5 == 0)
        {
            b++;
            t /= 5;
        }
    }

    cout << ((a < b) ? a : b);

    return 0;
}