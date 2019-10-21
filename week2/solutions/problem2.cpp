#include<stack>
#include<iostream>
using namespace std;
void fillStack(stack<int>& source){
	cout << "Enter element count"<<endl;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int current;
		cin >> current;
		source.push(current);
	}

}
void printStack(stack<int>& stck){
	while(!stck.empty()){
		int current = stck.top();
		stck.pop();
		cout << current << " ";
	}
	cout << endl;
}
void copyStack(stack<int>& source, stack<int>& destination){
	stack<int> help;
	while(!source.empty()){
		int current = source.top();
		source.pop();
		help.push(current);
	}
	while(!help.empty()){
		int current = help.top();
		help.pop();
		source.push(current);
		destination.push(current);
	}
}
int main(){
	stack<int> source, destination;
	fillStack(source);	
	copyStack(source,destination);
	printStack(destination);
	return 0;
}
