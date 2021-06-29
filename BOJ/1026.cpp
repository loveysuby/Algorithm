#include <bits/stdc++.h>
//Define
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int size; cin>>size;
	vector<int> A(size);
	vector<int> B(size);
	for(int idx=0;idx<size;idx++)
		cin>>A[idx];	
	for(int idx=0;idx<size;idx++)
		cin>>B[idx];	
	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end(), greater<int>());
	int sum = 0;
	for(int i=0;i<size;i++)
		sum += A[i] * B[i];
	
	cout<<sum;
	
    return 0;
}
