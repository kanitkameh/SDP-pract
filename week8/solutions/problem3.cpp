#include <iostream>
#include "tree.cpp"
#include <queue>
using namespace std;
bool isOrdered(tree<int> t){
	return t.empty() || 
		((t.RightTree().empty() || t.RootTree()<t.RightTree().RootTree()) && 
		 (t.LeftTree().empty() || t.LeftTree().RootTree()<t.RootTree()) && 
		 isOrdered(t.LeftTree()) && isOrdered(t.LeftTree())); 
}
int main(){
	tree<int> t;
	t.Create();
	cout << isOrdered(t) << endl;
	return 0;
}
