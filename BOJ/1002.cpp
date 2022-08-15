//Header
#include <iostream>
//Define
using namespace std;
//Global elements
int x, y, r1, x2, y2, r2;	//y1 : index() 함수에서 선언된 global var -> 선언 불가능

//Function
int dist() { return (x - x2)*(x - x2)+(y - y2)*(y - y2); } 
int sq(int x) { return x * x; }

//Driver
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int count;
	cin >> count;
	while (count--) {
		
		cin >> x >> y >> r1 >> x2 >> y2 >> r2;

		if (r1 == r2 && x == x2 && y == y2)
			cout << -1;
		else if (dist() > sq(r1 + r2))
			cout << 0;
		else if (dist() == sq(r1 + r2))
			cout << 1;
		else if (dist() < sq(r1 + r2)) {
			if (dist() > sq(r2 - r1))
				cout << 2;
			else if (dist() == sq(r2 - r1))
				cout << 1;
			else if (dist() < sq(r2 - r1))
				cout << 0;
		}
		cout << '\n';
	}
}