#include<iostream>
#include"tree.cpp"
using namespace std;
int smallestElement(tree<int> t1){
	while(!t1.LeftTree().empty()){
		t1=t1.LeftTree();
	}
	return t1.RootTree();
}
int main(){
	tree<int> t1;
	t1.Create();
	cout << smallestElement(t1);
	return 0;
}
