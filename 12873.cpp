#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main()
{  
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    
    for (int i=2; i<=N; i++) q.push(i);

    long long rot = 2;
    while (q.size() != 1)
    {
        long long next = rot*rot*rot%q.size();
        if (next == 0) next = q.size();

        for (int i=0; i<next-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
        rot++;
    }

    cout << q.front();

    return 0;
}