#include <iostream>

using namespace std;

int N, M;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    if (N == 1) cout << 1;
    else if (N == 2) cout << min(4, (M+1)/2);
    else
    {
        if (M >= 7) cout << max(4, M-2);
        else cout << min(4, M);
    }

    return 0;
}