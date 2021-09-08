#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//Driver
int main()
{
    fastio;
	int N,max_F,ans=0; cin>>N>>max_F;
	stack<int> s[7];
	//7개의 보드를 구성함. 처음에 0이 없으면 1번째 음이랑 2번째에새로 들어오는 음이랑 비교가 안 됨
	for(int i =0;i<7;i++)
		s[i].push(0);
	while(N--){
		int d,f; cin>>d>>f;
		//번호에 음이 있는데 들어오는 음이 더 작은 경우 -> 팝하고 카운트 반복 
		while(s[d].top()>f){
			s[d].pop(); ans++;
		}
		/*
		1. 번호에 음이없는경우 , 들어있는 음이 들어오는 음이랑 다른 경우 -> 추가하고 카운트
		2. 번호에 음이 있는데 들어오는 음이 더 높은 경우 -> 추가만 하고 카운트 
		=> 그냥 0으로 디폴트 넣고, 현재 잇는 음이랑 다르기만 하면 같은거 빠지고 높은거 체크되니 같은 case
		*/
		if(s[d].top()!=f){
			s[d].push(f); ans++;
		}
	}
	cout<<ans;


    return 0;
}