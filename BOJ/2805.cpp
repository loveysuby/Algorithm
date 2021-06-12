#include <iostream>
#include <vector>
#include <algorithm>
//Define
using namespace std;
#define ll long long

//Global elements


//Function
void Solve(vector<int>& vec, int cnt, int assign){
	

	int left=0,right=0, mid;
	int result = 0;
	
	for(int i=0;i<cnt;i++)		
		left = max(left, vec[i]);	
	
	while(left>right){
		ll sum =0;
		mid = (left + right)/2;
		
		for(int i=0;i<cnt;i++)
			if(vec[i]-mid >0)
				sum += vec[i]-mid;
			
		if(sum <assign){ //기준보다 덜 자름-> 더 많이 잘라야함 -> mid값을 낮춰서 잘라야 할 나무 target을 늘림 
			left = mid;
		}else{ // 기준값보다 많이 자름(res 충족) -> 자르는 양 줄이기 : mid 높여서 target 좁히고 재탐색 
			result = mid;
			right = mid + 1; 
		}
	}
	cout<<result; 
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int count, assign;
	cin>>count >>assign;	
	vector<int> vec(count);
	
	for(int i=0;i<count;i++)
		cin>>vec[i];
	
	Solve(vec,count, assign);

    return 0;
}
