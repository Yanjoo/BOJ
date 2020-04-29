#include <iostream>
#include <algorithm>

using namespace std;

int k;
int s[13];
int a[13];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        cin >> k;
        if (!k) break;
        for (int i=0; i<k; i++)
            cin >> s[i];
        for (int i=6; i<k; i++)
            a[i] = 1;

        do
        {
            for (int i=0; i<k; i++)
            {
                if (a[i]) continue;
                cout << s[i] << ' ';
            }
            cout << '\n';
        } while (next_permutation(a, a+k));
        cout << '\n';
    }

    return 0;
}