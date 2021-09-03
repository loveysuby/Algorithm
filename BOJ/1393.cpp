#include <bits/stdc++.h>
using namespace std;
int xs,ys,dx,dy,xe,ye,nx,ny;
int getGCD(int x, int y){
	int tmp;
	while(y != 0){
		tmp = x%y;
		x = y;
		y = tmp;
	}
	return x;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>xs>>ys>>xe>>ye>>dx>>dy;	
	int gcd = abs(getGCD(dx,dy));
	dx /= gcd; dy /= gcd;
	float MAX_d = sqrt(pow((xs-xe),2) + pow((ys-ye),2));
	int rx = xe,ry = ye;
	while(1){
		xe += dx; ye += dy;
		float dist = sqrt(pow((xs-xe),2) + pow((ys-ye),2));	
		if(dist <= MAX_d){
			MAX_d = dist;
			rx = xe; ry = ye;
			continue;
		}
		if(dist > MAX_d) break;
	}
	cout<<rx<<' '<<ry;
    return 0;
}