#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int,int> a[500001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int num;
        cin >> num;
        a[i] = {num, i};
    }

    sort(a + 1, a + n + 1);
    
    int result = 0;
    for (int i=1; i<=n; i++)
    {
        if (a[i].second - i > result) result = a[i].second - i;
    }

    cout << result + 1;

    return 0;
}
