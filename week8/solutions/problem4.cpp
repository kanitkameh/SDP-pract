#include <iostream>
#include "tree.cpp"
#include <queue>
#include <deque>
using namespace std;
//We want to compare node values two by two.
//When taking the left child of one of them 
//we take the right child of the other
bool isMirrored(tree<int> t1, tree<int> t2){
	if(t1.empty() && t2.empty())
		return true;	
	if(!t1.empty() && !t2.empty()){
		if(t1.RootTree() == t2.RootTree()){
			return isMirrored(t1.LeftTree(),t2.RightTree()) &&
			isMirrored(t1.RightTree(),t2.LeftTree());
		}
	}	
	return false;
}
//At first we will start comparing two roots
//but later the paths will split
bool isSymmetric(tree<int> t1){
	return isMirrored(t1,t1);
}
int main(){
	tree<int> t;
	t.Create();
	cout << isSymmetric(t) << endl;
	return 0;
}
