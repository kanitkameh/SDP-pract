#include <iostream>
#include <queue>
using namespace std;
void reverse(queue<int>& q){
	if(q.empty()){
		return;
	}
	int current = q.front();
	q.pop();
	reverse(q);
	q.push(current);
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
	reverse(q);
	while(!q.empty()){
		int current=q.front();
		q.pop();
		cout << current << endl;
	}
	return 0;
}
