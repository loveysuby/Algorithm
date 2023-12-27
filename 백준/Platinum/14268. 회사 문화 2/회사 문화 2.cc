#include <iostream>
#include <vector>
#define fastio                   \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL);
using namespace std;

int n, m;
int lzp[400001], tree[400001]; // lazy propagation 해서 순회하면서 subfix
int st[100001], en[100001];
vector<vector<int>> p;

void dfs(int curr, int &order)
{
	st[curr] = ++order;
	for (int next : p[curr])
		dfs(next, order);
	en[curr] = order; // end는 자식들이 다 끝나고 나서야 정해짐
}

void runlzy(int node, int s, int e)
{
	if (lzp[node])
	{
		tree[node] += (e - s + 1) * lzp[node]; // lzy로 전달된 값만큼 prefix에 더함
		if (s != e)
		{
			lzp[node * 2] += lzp[node];
			lzp[node * 2 + 1] += lzp[node];
		}
		lzp[node] = 0; // 노드에서 초기화
	}
}

void update(int node, int s, int e, int i, int j, int v)
{
	runlzy(node, s, e);
	if (j < s || e < i)
		return;
	if (i <= s && e <= j) // 구간에 포함될 때만 업데이트
	{
		tree[node] += (e - s + 1) * v;
		if (s != e)
		{
			lzp[node * 2] += v;
			lzp[node * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, i, j, v);
	update(node * 2 + 1, m + 1, e, i, j, v);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int idx)
{
	runlzy(node, s, e);
	if (idx < s || e < idx)
		return 0;
	if (s == e)
		return tree[node];
	int m = (s + e) / 2; // 리프아니면 반갈

	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}

int main()
{
	fastio;
	cin >> n >> m;
	p.resize(n + 1);
	int x;
	cin >> x;
	for (int i = 2; i < n + 1; i++)
	{
		cin >> x;
		p[x].push_back(i);
	}
	int order = 0;
	dfs(1, order);
	int qMode, y;
	for (int i = 0; i < m; i++)
	{
		cin >> qMode;
		if (qMode == 1)
		{
			cin >> x >> y;
			update(1, 1, n, st[x], en[x], y);
		}
		else if (qMode == 2)
		{
			cin >> x;
			cout << query(1, 1, n, st[x]) << endl;
		}
	}
}