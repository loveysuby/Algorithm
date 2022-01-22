#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int N,K,ans;
int order[101];
bool isRun[101];
vector<int> plug;
int main(){
	fastio;
	cin>>N>>K;
	
	for(int i=0;i<K;i++)
		cin>>order[i];
	
	for(int i=0;i<K;i++){	
		int curr = order[i];
		//현재 순서의 제품이 이미 plug에 사용중이라면 패스
		if(isRun[curr]) continue;
		
		//현재 제품이 미사용중이고 + 빈 플러그가 있다면, 현재 제품을 추가
		if((int)plug.size()<N){
			plug.push_back(curr);
			isRun[curr] = true;
			continue;
		}
		
		//현재 제품이 있는 경우라면 (이후 사용 횟수가 없는 것 || 가장 나중에 쓰는 것 빼기)
		int idx = 0, lastp = 0;
		for(int j=0;j<N;j++){
			int lastidx = 1e9;
            //현재 plug에 할당된 값과 일치하는 이후 순서의 값이 있는 경우-> 최 후열 순서의 값이 빠지는 값이 됨
			for (int k=i+1; k<K; k++){
				if(plug[j] == order[k]){
					lastidx = k;
					break;
				}
			}
			if(idx<lastidx){
				idx = lastidx; lastp = j;
			}
		}
		//실행 상태를 바꿔주고 새로운 값 할당
		isRun[plug[lastp]] = false;
		plug[lastp] = curr;
		isRun[curr] = true;
        ans++;
	}
	cout<<ans;
}