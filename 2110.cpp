#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int a[200000];
int result;

bool check(int x)
{
    int n = 1;
    int s = 0;
    for (int i=1; i<N; i++)
    {
        if (a[i]-a[s] >= x)
        { 
            n++;
            s = i;
        }
    }
    return n >= C;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> C;

    for (int i=0; i<N; i++) 
        cin >> a[i];

    sort(a, a+N);

    int l = 1;
    int r = a[N-1]-a[0];

    while (l <= r)
    {
        int m = (l+r)/2;
        if (check(m))
        {
            result = max(result, m);
            l = m+1;
        }   
        else 
            r = m-1;
    }

    cout << result;

    return 0;
}