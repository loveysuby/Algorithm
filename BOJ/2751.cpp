//Header
#include <iostream>
#include <algorithm>
//Define
using namespace std;

//Global elements


//Function


//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[1000001];
	int N; cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
 
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
		cout<<arr[i]<<'\n';
	
    return 0;
}