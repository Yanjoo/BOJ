#include <bits/stdc++.h>

using namespace std;

struct f
{
    int p, f, s, v;
    int idx;
    int price;
};

int N;
int mp, mf, ms, mv, price;
f arr[500];
bool check[15];
vector<int> v;
int result = 987654321;

void solve(int idx, int mmp, int mmf, int mms, int mmv, int price)
{
    if (idx > N)
    {
        return;
    }

    if (mmp >= mp && mmf >= mf && mms >= ms && mmv >= mv)
    {
        if (result < price) return;
        
        if (result == price)
        {
            string a = "", b="";
            for (int i=0; i<N; i++)
            {
                if (check[i]) b += ((i+1)+'0'); 
            }
            for (int i=0; i<v.size(); i++)
                a += (v[i] + '0');
            
            if (a <= b) return; 
        }

        v.clear();
        result = price;
        for (int i=0; i<N; i++)
        {
            if (check[i]) v.push_back(i+1);
        }
    }
    for (int i=idx; i<N; i++)
    {
        check[i] = true;
        solve(i+1, mmp + arr[i].p, mmf + arr[i].f, mms + arr[i].s, mmv + arr[i].v, price + arr[i].price);
        check[i] = false;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    for (int i=0; i<N; i++) 
    {
        cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].price;
        arr[i].idx = i+1;
    }

    solve(0, 0, 0, 0, 0, 0);

    if (result == 987654321)
    { 
        cout << -1;
    }
    else
    {
        cout << result << '\n';
        for (int num : v)
            cout << num << ' ';
    }
    
    return 0;
}
