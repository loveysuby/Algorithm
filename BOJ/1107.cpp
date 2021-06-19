#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int errKey[10];

//Function
int chkDirectBtn(int channel){
	//근접한 숫자를 버튼으로 누르는 법 
	int pushKeyCnt=0;
	
	if(channel==0) 
		pushKeyCnt = (errKey[0]>0) ? 0 : 1;	

	while(channel>0){
		//채널 자리로 다이렉트로 못 갈 때(중간에 고장난버튼 있음) -> 이동 불가능. 
		if(errKey[channel%10]) return 0;
		pushKeyCnt++;
		channel /= 10;
	}
	
	return pushKeyCnt;	
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int channel, errKeyCount;
	cin>>channel>>errKeyCount;
	
	for(int i=0;i<errKeyCount;i++){
		int key; cin>>key;
		errKey[key] = 1;	
	}	
	
	int result = abs(channel-100);
		
	//(뺴도 복잡도 안변함) => base case : 얘네는 + - 가 곧 최소
	// if(channel>=98 && channel<=103){
	// 	cout<<result;
	// 	return 0;
	// }
	
	// int directBtn = chkDirectBtn(i); //숫자버튼으로 입력된 수
	for(int i = 0;i< 999999 ;i++)
		if(chkDirectBtn(i)>0) 
			result = min(result, chkDirectBtn(i) + abs(i- channel));	
		
	cout<<result;
	
	return 0;
	//모든 연산 가능 범위의 채널을 탐색해야만 근접 채널에 대한 접근여부와 버튼 + (+/-)키 조합 연산 가능. 다른방법 없는 듯
	//타겟 370000 일때, 에러키 2345면? (370000-100000) > [better](600000-370000) => 검사 범위가 50만 이상.. 

}

/*
기록할 필요 있는 듯 (자주 하는 실수)
특정 state를 어떤 변수에 남겨두는 습관이 있다. (정상)
근데 reculsion or tabulation function을 세울 때 처음 설정한 변수를 계속 쓰다 보니까 result에서 갱신이 되지 않음.

여기서는 result값에 할당한 값 (+ / - 로만 채널을 이동하는 case)를 다른 변수(pmCnt) 에 빼서 저장하고,
마지막 loop에서 min의 parameter로 pmCnt를 넣었다. 이러다 보니 i가 1000000까지 가는 과정에서 이미 최소값이 저장되어 있더라도
pmCnt보다 크면 result를 재 갱신했다. 

=> 특정 state를 flag로 찍어두고 이를 reference하는 것은 유의미하나, 상태만을 특정하면 되는 상황에서는 변수의 값이 바뀔 수 있음을 인지할 필요가 있다.

앞으론 이런 실수는 없겠지만,, 미래의 내가 이런 오류를 겪을 때를 대비하여 남긴다.


*/
