#include<iostream>
#include"tree.cpp"
#include<string.h>
using namespace std;
bool isLeaf(tree<string> t1){
	return t1.RightTree().empty() && t1.LeftTree().empty();
}
bool implication(bool p, bool q){
	return !p || q;
}
bool evaluate(tree<string> t1){
	if(isLeaf(t1)){
		return t1.RootTree().compare("true")==0?true:false;
	}else if(!t1.RootTree().compare("&")){
		return evaluate(t1.LeftTree()) && evaluate(t1.RightTree());
	}else if(!t1.RootTree().compare("v")){
		return evaluate(t1.LeftTree()) || evaluate(t1.RightTree());
	}else if(!t1.RootTree().compare("<=>")){
		return evaluate(t1.LeftTree()) == evaluate(t1.RightTree());
	}else if(!t1.RootTree().compare("=>")){
		return implication(evaluate(t1.LeftTree()),evaluate(t1.RightTree()));
	}
	return false;	
}
int main(){
	tree<string>t1;
	t1.Create();
	cout << (evaluate(t1)?"true":"false") << endl;
	return 0;
}
