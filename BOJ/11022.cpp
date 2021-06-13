#include <iostream>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	int num1, num2;
	for (int i = 1; i <= cnt; i++) {
		cin >> num1 >> num2;
		cout << "Case #" << i << ": " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	}
	return 0;
}