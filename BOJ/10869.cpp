#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b;
	while (1) {
		cin >> a >> b;
		if (!(a<1 || b>10000))
			break;
		else
			continue;
	}
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b;
	return 0;
}