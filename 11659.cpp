#include <iostream>

using namespace std;

int N, M;
int arr[100001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i=1; i<=N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    while (M--)
    {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << '\n';
    }

    return 0;
}