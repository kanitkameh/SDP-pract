#include <iostream>
#include <queue>
using namespace std;
int smallestElement(queue<int> q){
	int max=q.front();
	while(!q.empty()){
		int current = q.front();
		q.pop();
		if(current>max){
			max = current;
		}
	}
	return max;
}
int main(){
	int n;
	cin >> n;
	queue<int> q;

	for(int i=0;i<n;i++){
		int current;
		cin >> current;
		q.push(current);
	}
	cout << smallestElement(q);
	return 0;
}
