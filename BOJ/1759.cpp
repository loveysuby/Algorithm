#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements

int L, C; 
char words[16];
char password[16];
//Function

//x: 자음 Y; 모음 , wordsize인 단어에서 현재 체크해야 할 idx 와 
//지금까지 조합된 단어의 자 모음 수를 전달 => wordsize가 목적 도달하면 pw출력
void Solve(int idx, int x, int y, int wordSize){
	if(wordSize==L){ //단어 사이즈 일치 : 자모음 확인
		if(x>=2 && y>=1){
			for(int i=0;i<L;i++)
				cout<<password[i];
			cout<<"\n";
		}	
		return;	
	}
	else{ //단어 개수 부족 : 현재 위치부터 목표 size까지 자모음 case별로 탐색
		for(int i=idx;i<C;i++){
			password[wordSize] = words[i];
			if(words[i]=='a'||words[i]=='e'||words[i]=='i'||words[i]=='o'||words[i]=='u')
				Solve(i+1,x,y+1,wordSize+1);
			else
				Solve(i+1,x+1,y,wordSize+1);	
		}	
	}	
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	cin>>L>>C;
	
	for(int i=0;i<C;i++)
		cin>>words[i];
	sort(words,words+C);	
	Solve(0,0,0,0);
	
    return 0;
}
