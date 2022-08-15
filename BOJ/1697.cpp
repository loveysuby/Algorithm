#include <bits/stdc++.h>
//Define
using namespace std;
#define MAX 100300
//Global elements
int ptr,target;
int depth = 0;
bool vis[MAX+1]={false};	
queue<int> q;	
//Function
int bfs(int ptr){
	if(ptr == target)
		return 0;	
	
	q.push(ptr);//5
	vis[ptr] = true;
	
	
	/*
	index로 접근하고자 할 때, 먼저 접근을 시도하면 outofBounds 오류의 원인이 된다. (test case는 정상 작동하여 찾기 힘듬)
	index의 범위를 판별하여 특정 원소에만 접근하고자 한다면 index 값을 먼저 검사한 이후의 연산자에서 접근하자. (값 안맞으면 array 접근 전에 pass)
	*/
	while(!q.empty()){
		int qSize = q.size(); //1 321 9
		
		for(int i=0;i<qSize;i++){	
			int node = q.front();//5 4610 3 5 8...
			q.pop();//큐빔 6 10 /10 0 
			
			if(node == target){//base
				q = queue<int>();
				return depth;
			}//case1 4-3 6-5 10-9
			if(node-1>=0&&!vis[node-1]){
				q.push(node-1);
				vis[node-1]=true;
			}//case2 4-5 6-7 10-11
			if(node+1<=MAX&&!vis[node+1]){
				q.push(node+1);
				vis[node+1]=true;
			}//case3 4-8 6-12 10-20
			if(node * 2<=MAX&&!vis[node * 2]){
				q.push(node * 2);
				vis[node * 2]=true;
			}
		}		
		depth++;
	}
	return depth;
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>ptr>>target;

	cout<<bfs(ptr);
	
    return 0;
}
