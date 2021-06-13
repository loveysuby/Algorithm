#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a>1 &&b>1&&c>1&& a <= 10000 && b <= 10000 && c <= 10000)
			break;
		else
			continue;
	}
	cout << (a+b)%c << endl;
	cout << ((a%c)+(b%c))%c << endl;
	cout << (a*b)%c << endl;
	cout << ((a%c)*(b%c))%c << endl;
	return 0;
}
