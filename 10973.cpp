#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[10000];

bool nextPermutation(int * a, int n)
{
    int i = n - 1;
    while (i > 0 && a[i-1] < a[i]) i--;
    if (i <= 0) return false;
    int j = n-1;
    while (a[j] > a[i-1]) j--;
    swap(a[i-1], a[j]);
    j = n-1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++, j--;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> a[i];

    if (nextPermutation(a, N)) 
        for (int i=0; i<N; i++) 
            cout << a[i] << ' ';
    else cout << -1;

    return 0;
}