#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int person, target, flag;
	cin>>person>>target>>flag;
	//target 번째로 flag의 순서가 되는 사람?
	int idx=0, loop = 1, curr = -1;//0번째부터 시작
	
	while(1){
		if(idx == target) break;
		for(int time = 0;time<((loop+1) * 2) + 4; time++){
			curr++;
			//4번 시행 이전에 0이 타겟인 경우 -> 0, 2 번째를 카운트		
			if(flag == 0 && time<4 && time % 2 == 0) idx++;
			else if(flag == 1 && time<4 && time % 2 == 1) idx++;
			//4번 시행 이후에 0이 타겟인 경우 ->해당 loop의 5~loop+5 범위 안에만 있음
			else if(flag == 0 && time>=4 && time <= loop + 4) idx++;
			//4번 시행 이후에 1은 loop + 4부터 끝까지 전부 다 1
			else if(flag == 1 && time >= loop + 5) idx++;
			if(idx == target) break;
		}
		loop++;
	}
	cout<<curr % person;
}