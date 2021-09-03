#include <bits/stdc++.h>
using namespace std;
int getGCD(int x, int y){
	int tmp;
	while(y != 0){
		tmp = x%y;
		x = y; 
		y = tmp;
	}
	return x;
	// BOJ에서 이렇게 gcd 구현을 하면 DivisionByZero Exception 발생. 이유 찾아보자 (gcc컴파일러 해석 관련??)
	// 	return (x % y == 0 ? y : getGCD(y,x%y));
	
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int xs,ys,dx,dy,xe,ye,nx,ny;
	cin>>xs>>ys>>xe>>ye>>dx>>dy;
	//출력 형식이 정수에 한정되므로, 변화량을 정수 단위로 끊어줘야 함. gcd의 출력값이 음수인 경우, 역벡터를 형성하므로 절대값으로 나눈다.
	int gcd = abs(getGCD(dx,dy));
	dx /= gcd; dy /= gcd;
	//시작 상태의 거리와 위치를 비교군으로 저장한다. 시간에 따라 멀어지는 벡터면 이 상태가 최소값이 될 것이다.
	float MAX_d = sqrt(pow((xs-xe),2) + pow((ys-ye),2));	
	int rx = xe,ry = ye;
	
	while(1){
		xe += dx; ye += dy;
		float dist = sqrt(pow((xs-xe),2) + pow((ys-ye),2));
		
		//정수 단위로 증가하는 상태를 처음 상태와 비교하여 거리가 줄어드는 경우를 채용한다.
		if(dist <= MAX_d){
			//거리가 줄어드는 중인 상태에는 해당 dist가 비교 가능한 최대 거리가 되므로 거리량과 이동한 점의 위치를 저장한다.
			MAX_d = dist;
			rx = xe; ry = ye;
			continue;
		}
		//Base case
		if(dist > MAX_d) break;
	}
	cout<<rx<<' '<<ry;
}