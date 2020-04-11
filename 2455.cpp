#include <iostream>

using namespace std;

int cnt;
int result;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i=0; i<4; i++)
    {
        int x, y;
        cin >> x >> y;
        cnt = cnt - x + y;
        if (result < cnt) result = cnt;
    }

    cout << result;

    return 0;
}