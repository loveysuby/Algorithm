
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
vector<int> parent, depth;

int iter, NodeCount;

void dfs(int &curr, const int &dep)
{
	depth[curr] = dep;
	for (int i = 0; i < vec[curr].size(); i++) //vec[curr].size() == NodeCount
	{
		int target = vec[curr][i];
		dfs(target, dep + 1);
	}
}

int main()
{
	cin >> iter;
	while (iter--)
	{
		cin >> NodeCount;

		//NodeCount 값을 입력받은 크기만큼 2-dimensin vec, parent / depth 벡터 생성.
		vec.assign(NodeCount + 1, vector<int>());
		parent.assign(NodeCount + 1, 0);
		depth.assign(NodeCount + 1, 0);

		int x, y;
		for (int i = 0; i < NodeCount - 1; i++)
		{
			cin >> x >> y;
			vec[x].push_back(y);
			//vec의 key값은 현재 노드, inner vector의 값은 자식 노드를 가리킨다.
			parent[y] = x;
		}
		for (int j = 1; j <= NodeCount; j++)
		{
			if (!parent[j])
			{
				parent[j] = j;
				dfs(j, 1);
				break;
			}
		}
		cin >> x >> y;
		while (depth[x] != depth[y])
		{
			if (depth[x] < depth[y])
				y = parent[y];
			else
				x = parent[x];
		}
		while (x != y)
		{
			x = parent[x];
			y = parent[y];
		}
		cout << x << endl;
	}
}