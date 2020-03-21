#include <iostream>

using namespace std;

int K, N, M;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> K >> N >> M;

    cout << (K * N - M > 0 ? K*N-M : 0);

    return 0;
}