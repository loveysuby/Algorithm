#include <bits/stdc++.h>
using namespace std;
struct Student{
	string name;
	int kor,eng,math;
};
//Function
bool cmp(const Student &u, const Student &v){
	if(u.kor == v.kor){
		if(u.eng==v.eng){
			if(u.math==v.math)
				return u.name<v.name;
			else
				return u.math>v.math;		
		}
		else
			return u.eng<v.eng;
	}
	else
		return u.kor>v.kor;
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int N; cin>>N;
	vector<Student> v(N);
	for(int i =0;i<N;i++)
		cin>> v[i].name>>v[i].kor>>v[i].eng>>v[i].math;
	sort(v.begin(),v.end(),cmp);
	for(int i =0;i<N;i++)
		cout<<v[i].name<<'\n';
    return 0;
}