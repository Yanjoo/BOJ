#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[8];
int result;

int sum()
{
    int sum = 0;
    for (int i=0; i<N-1; i++)
        sum += abs(a[i] - a[i+1]);
    return sum;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> a[i];

    sort(a, a+N);

    do
    {
        result = max(result, sum());
    } while (next_permutation(a, a+N));

    cout << result;

    return 0;
}