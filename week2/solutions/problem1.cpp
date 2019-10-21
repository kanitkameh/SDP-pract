#include <iostream>
#include <stack>
using namespace std;
void printInReverse(char* str){
	stack<char> stck;
	while(*(str++))
		stck.push(*(str-1));
	while(!stck.empty()){
		char current = stck.top();
		stck.pop();	
		cout << current;
	}	
}
int main(){
	char str[20];
	cin >> str;
	printInReverse(str);
	return 0;
}
