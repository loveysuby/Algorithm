#include <iostream>
using namespace std;

int main() {
	int hour, min, sec, time;
	cin >> hour >> min >> sec;
	cin >> time;
	sec += time % 60;
	min += time / 60;
	if (sec >= 60) {	
		min += sec / 60;
		sec %= 60;
	}
	if (min >= 60) {
		hour += min / 60;
		min %= 60;
	}
	if (hour >= 24)
		hour %= 24;
	cout << hour << " " << min << " " << sec << "\n";
	return 0;
}