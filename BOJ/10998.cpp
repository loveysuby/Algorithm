#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (!(a * b > 0 || a * b < 100)) {
		return 0;
	}
	cout << a * b << endl;
	return 0;
}