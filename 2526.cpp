#include <iostream>

using namespace std;

int N, P;
pair<bool, int> check[98];
int cnt;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> P;
    check[N].first = true;

    int next = N*N%P;
    while (!check[next].first)
    {
        cnt++;
        check[next].second = cnt;
        check[next].first = true;
        next = next*N%P;
    }

    cout << cnt - check[next].second + 1;

    return 0;
}