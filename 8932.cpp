#include <bits/stdc++.h>

using namespace std;

int T;
int s[7];
double A[7] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
double B[7] = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
double C[7] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    while (T--)
    {
        for (int i=0; i<7; i++) cin >> s[i];
        int result = 0;
        result += (int) (A[0] * pow(B[0]- s[0], C[0]));
        result += (int) (A[1] * pow(s[1]- B[1], C[1]));
        result += (int) (A[2] * pow(s[2]- B[2], C[2]));
        result += (int) (A[3] * pow(B[3]- s[3], C[3]));
        result += (int) (A[4] * pow(s[4]- B[4], C[4]));
        result += (int) (A[5] * pow(s[5]- B[5], C[5]));
        result += (int) (A[6] * pow(B[6]- s[6], C[6]));
        cout << result << '\n';
    }


    return 0;
}
