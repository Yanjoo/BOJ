#include <iostream>

using namespace std;

int n;
int inorder[100001], postorder[100001];
int position[100001];

void solve(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe) return;

    int root = postorder[pe];
    int p = position[root];
    int l = p - is;

    cout << root << ' ';
    solve(is, p-1, ps, ps+l-1);
    solve(p+1, ie, ps+l, pe-1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i=1; i<=n; i++) 
    {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }
    for (int i=1; i<=n; i++) cin >> postorder[i];

    solve(1, n, 1, n);

    return 0;
}