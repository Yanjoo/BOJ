#include <iostream>

using namespace std;

int on[4], out[4];
int cnt;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i=0; i<4; i++)
    {
        cin >> out[i] >> on[i];
        int t = cnt;
        t = t - out[i] + on[i];
        if (t > cnt) cnt = t;
    }

    cout << cnt;

    return 0;
}