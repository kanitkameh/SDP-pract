#include <iostream>
#include <stack>

using namespace std;

class myQueue{
	stack<int> s1;
	stack<int> s2;
	void transferStack(stack<int> source,stack<int> destination){
		while(!source.empty()){
			int current = source.top();
			source.pop();
			destination.push(current);
		}
	}
public:
	void enqueue(int n){
		s1.push(n);		
	}
	int  dequeue(){
		transferStack(s1,s2);
		int result = s2.top();
		s2.pop();
		transferStack(s2,s1);
		return result;
	}
	bool empty(){
		return s1.empty();
	}
};
int main(){
	myQueue q;
	int n,current;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> current;
		q.enqueue(current);
	}
	while(!q.empty()){
		current = q.dequeue();
		cout << current << endl;
	}
	return 0;
}
