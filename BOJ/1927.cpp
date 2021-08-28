#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100001
struct minHeap{
	vector<unsigned int> heap;
	int hn;
	minHeap(int size) : heap(size+1, pow(2,31)), hn(0) {}
	
	void push(unsigned int num){
		heap[++hn] = num;
		for(int i = hn; i>1 && heap[i]<heap[i/2]; i/=2)
			swap(heap[i],heap[i/2]);
	}
	int pop(){
		if(hn == 0) return 0;
		int result = heap[1];
		heap[1] = heap[hn];
		heap[hn--] = pow(2,31);
		
		for(int i = 1; i * 2 <= hn;){
			if(heap[i]<heap[i*2] && heap[i]<heap[i*2+1]) break;
			else if(heap[i * 2] < heap[i * 2 + 1]){
				swap(heap[i],heap[i*2]);
				i *= 2;
			}
			else{
				swap(heap[i],heap[i*2+1]);
				i = i*2+1;
			}	
		}
		return result;
	}	
};
int main(){
	fastio;
	int N; cin>>N;
	minHeap h(N);
	while(N--){
		unsigned int elem; cin>> elem;
		if(elem == 0) cout<<h.pop()<<'\n';
		else
			h.push(elem);
	}
}