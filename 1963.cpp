#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int T;
int A, B;
bool prime[10000];
bool visit[10000];
vector<int> primes;

bool canGo(int v, int n)
{
    string from;
    string to = to_string(n);

    for (int i=0; i<4; i++)
    {
        from = to_string(v);
        for (int j=0; j<=9; j++)
        {
            from[i] = j + '0';
            if (from == to) return true;
        }
    }

    return false;
}

int bfs(int v, int cnt)
{
    queue<int> q;
    visit[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            v = q.front();
            q.pop();
            if (v == B) return cnt;
            for (int i=0; i<primes.size(); i++)
            {
                if (!visit[primes[i]] && canGo(v, primes[i]))
                {
                    q.push(primes[i]);
                    visit[primes[i]] = true;
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    prime[1] = true;
    for (int i=2; i<10000; i++)
    {
        if (!prime[i])
        {
            for (int j=i*i; j<10000; j+=i) 
                prime[j] = true;
        }
    }

    for (int i=1000; i<10000; i++)
    {
        if (!prime[i]) 
            primes.push_back(i);
    }

    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        memset(visit, false, sizeof(visit));
        int result = bfs(A, 0);
        if (result == -1) cout << "Impossible" << '\n';
        else cout << result << '\n';
    }

    return 0;
}