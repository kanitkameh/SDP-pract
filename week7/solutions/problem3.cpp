#include<iostream>
#include"tree.cpp"
using namespace std;
void print(tree<int> t1){
	if(t1.empty()){
		return;
	}
	print(t1.LeftTree());
	cout << t1.RootTree() << " ";
	print(t1.RightTree());
}
int main(){
	tree<int> t1;
	t1.Create();
	print(t1);
	return 0;
}
