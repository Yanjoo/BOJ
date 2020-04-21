#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double x, y, c;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> x >> y >> c;

    double left = 0;
    double right = min(x, y);

    while (abs(right-left) > 1e-6)
    {
        double mid = (left + right) / 2.0;
        double a = sqrt(x*x - mid*mid);
        double b = sqrt(y*y - mid*mid);
        double h = (a*b)/(a+b);
        if (h > c) left = mid;
        else right = mid;
    }
    cout << fixed;
    cout.precision(3);
    cout << left;

    return 0;
}