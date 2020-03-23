#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];
int tree[400001];
int tree2[400001];

void init(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = arr[start];
		tree2[node] = arr[start];
	}
	else
	{
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		tree2[node] = max(tree2[node * 2], tree2[node * 2 + 1]);
	}
}

int minQuery(int node, int start, int end, int i, int j)
{
	if (i > end || j < start) return -1;
	if (i <= start && j >= end) return tree[node];

	int m1 = minQuery(2 * node, start, (start + end) / 2, i, j);
	int m2 = minQuery(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
} 

int maxQuery(int node, int start, int end, int i, int j)
{
	if (i > end || j < start) return -1;
	if (i <= start && j >= end) return tree2[node];

	int m1 = maxQuery(2 * node, start, (start + end) / 2, i, j);
	int m2 = maxQuery(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return max(m1, m2);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	init(1, 1, N);

	int from, to;
	while (M--)
	{
		cin >> from >> to;
		cout << minQuery(1, 1, N, from, to) << ' ' << maxQuery(1, 1, N, from, to)  << '\n';
	}

	return 0;
}