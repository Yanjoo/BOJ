#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
int graph[101][101];
bool check[102][102];
int cnt;
int dx = 1, dy = 1;
int d = 1;
pair<int, int> head[4] = {{-1,0},{0,1},{1,0},{0,-1}};
queue<pair<int, int>> tail;
queue<pair<int, char>> change;

int right(int d)
{
	return (d + 1 > 3) ? 0 : d + 1;
}

int left(int d)
{
	return (d - 1 < 0) ? 3 : d - 1;
}

void solve()
{
	while (true)
	{
		dx += head[d].first;
		dy += head[d].second;

		if (check[dx][dy]) break;

		check[dx][dy] = true;
		tail.push({ dx, dy });
        
		if (graph[dx][dy])
			graph[dx][dy] = 0;
		else
		{
			check[tail.front().first][tail.front().second] = false;
			tail.pop();
		}

		cnt++;

		if (cnt == change.front().first)
		{
			if (change.front().second == 'D') d = right(d);
			else d = left(d);
			change.pop();
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int a; char b;
		cin >> a >> b;
		change.push({ a, b });
	}
	for (int i = 0; i <= N + 1; i++)
		check[i][0] = check[i][N+1] = check[0][i] = check[N + 1][i] = true;
	
    check[dx][dy] = true;
	tail.push({dx,dy});

	solve();

	cout << cnt + 1;
	return 0;
}
