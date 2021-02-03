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

/*
==> 굳이 배열을 생성할 필요가 없었다. (이게 깔끔한 코드인지는 모르겠지만 ,,,)
graph[0]의 배열을 resize 해주고 그 안에 값을 저장해서 max값을 끌어내면 굳이 배열을 안써도 된다.

다만... 어차피 homogeneous database 라서 memory size 는 같을 듯 .. 답은 1325로 제출했다. 

===>제출 결과 틀렸다 함.. 
    1. vector의 database 형태와 정적 배열이 데이터 사용 면에서 메모리차지하는 양
    2. 동적 data를 iterator로 호출하는 습관이 썩 좋은거같진 않다. 진짜인지 확인해보자 !
*/

//N개의 컴퓨터만 쓰이므로 vector를 N+1로 resize한다.(가변 배열)
vector<vector<int>> graph;
vector<bool> check;

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
    graph[0] = vector<int>(countNode, 0);

    for (int i = 1; i <= countNode; i++)
    {
        check = vector<bool>(countNode + 1, false);

        graph[0][i] = dfs(i);
        maxNode = max(maxNode, graph[0][i]);
    }
    for (int i = 0; i < countNode; i++)
        if (graph[0][i] == maxNode)
            cout << i << ' ';
    return 0;
}