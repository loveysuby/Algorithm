#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N,M; cin>>N>>M;
	int pack=1e9, single=1e9;
	for(int i=0;i<M;i++){
		int tpack, tsin;
		cin>>tpack>>tsin;
		//어차피 제일 단가 싼걸로만 브랜드 상관없이 사면 됨
		pack = min(tpack, pack);//6개 이상일때 무조건 끼고 들어감
		single = min(tsin, single);// 6개 이하일때 최적해	
	}
	/*
	3가지 case
	single * N	(N/6) + 1 * package		N/6 package + N%6 single
	*/
	int sol1 = N * single, sol2 = (N/6 + 1) * pack, sol3 = (N/6) * pack + (N%6) * single;
	cout<<min(sol1,min(sol2,sol3));
}