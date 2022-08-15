#include <iostream>
using std::cin;
using std::cout;


int main() {
	int a, b;
	while (1) {
		cin >> a;
		cin >> b;
		if (a > 0 && a <= 10 && b > 0 && b < 10)
			break;
		else
			continue;		
	}
	cout << a + b;
	return 0;
}