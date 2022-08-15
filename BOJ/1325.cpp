#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
B를 해킹하면 A 역시 해킹이 가능하므로, B1=A1(=B2)=>A2 식의 방향 그래프가 형성된다
그래프를 dfs 로 돌면서 연결노드가 없는 끝 지점까지 지나가는 최대 노드 수를 센다
각 노드가 지나갈 수 있는 연결노드의 수(해킹가능한 컴퓨터)의 배열에서 최대값 구해서
그 최대값과 match되는 computer key를 출력하자.
*/

//N개의 컴퓨터만 쓰이므로 vector를 N+1로 resize한다.(가변 배열)
vector<vector<int>> graph;
vector<bool> check;
int PassedNodeArr[10001];

int dfs(int node) //dfs(3) : 3에서 연결된(신뢰된) node의 최대 개수
{
    check[node] = true;
    int result = 0;
    for (int i = 0; i < (int)graph[node].size(); i++)
        if (!check[graph[node][i]])
            result += dfs(graph[node][i]) + 1;
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int countNode, edges;
    cin >> countNode >> edges;

    graph.resize(countNode + 1);
    check.resize(countNode + 1);

    int a, b;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int maxNode = 0;
    for (int i = 1; i <= countNode; i++)
    {
        check = vector<bool>(countNode + 1, false);
        PassedNodeArr[i] = dfs(i);
        maxNode = max(maxNode, PassedNodeArr[i]);
    }
    for (int i = 1; i <= countNode; i++)
        if (PassedNodeArr[i] == maxNode)
            cout << i << ' ';
    cout << '\n';

    return 0;
}