#include<iostream>
#include<stack>
using namespace std;
bool isCorrect(char * str){
	stack<char> stck;
	for(int i=0;str[i];i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			stck.push(str[i]);
		}else if(!stck.empty()){
			if(str[i]==')' && stck.top()=='('){
				stck.pop();
			}else if(str[i]=='}' && stck.top()=='{'){
				stck.pop();	
			}else if(str[i]==']' && stck.top()=='['){
				stck.pop();	
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
	return stck.empty();
}
int main(){
	char str[30];
	cin >> str;
	cout << isCorrect(str) << endl;
	return 0;
}
