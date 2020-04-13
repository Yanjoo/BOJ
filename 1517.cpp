#include <iostream>

using namespace std;

int N;
int A[500000];
int B[500000];
long long result;

void merge(int l, int mid, int r)
{
    int i = l;
    int j = mid+1;
    int idx = 0;
    while (i <= mid || j <= r)
    {
        if (i <= mid && (j > r || A[i] <= A[j]))
            B[idx++] = A[i++];
        else
        {
            B[idx++] = A[j++];
            result += (long long)mid - i + 1;
        }   
    }

    for (int i=l; i<=r; i++) A[i] = B[i-l];
}

void mergesort(int l, int r)
{
    if (l < r)
    {
        int mid = (l+r) / 2;
        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(l, mid, r);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];

    mergesort(0, N-1);

    cout << result;

    return 0;
}