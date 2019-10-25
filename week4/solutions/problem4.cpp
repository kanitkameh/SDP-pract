#include <queue>
#include <iostream>
using  namespace std;
int getNumberFromSequence(int n,int index){
	int current = n;
	queue<int> q;
	q.push(current);
	for(int i=0;i<index;i++){
		current = q.front();
		q.push(current+1);
		q.push(current*2);
		q.pop();
	}
	return current;
}
int main(){
	int i,n;
	cin >> n >> i;
	cout << getNumberFromSequence(n,i);
}
