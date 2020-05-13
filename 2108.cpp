#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int a[500001];
int sum;

void print()
{
    vector<pair<int, int>> v;
    int cnt = 1;
    for (int i=0; i<N; i++)
    {
        if (a[i] == a[i+1]) 
            cnt++;
        else
        {
            v.push_back({-cnt, a[i]});
            cnt = 1;
        }
    }

    sort(v.begin(), v.end());

    if (v.size() > 1 && v[1].first == v[0].first)
        cout << v[1].second << '\n';
    else
        cout << v[0].second << '\n';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i=0; i<N; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+N);
    a[N] = 987654321;

    cout << fixed;
    cout.precision(0);
    cout << sum / (double) N << '\n';
    cout << a[N/2] << '\n';
    if (N > 1)
        print();
    else 
        cout << a[0] << '\n';
    cout << a[N-1] - a[0];

    return 0;
}