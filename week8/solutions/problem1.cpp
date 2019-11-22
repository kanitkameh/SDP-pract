#include <iostream>
#include "tree.cpp"
#include <queue>
using namespace std;
void dfs(tree<int> t){
	if(t.empty()){
		return;
	}
	cout << t.RootTree() << endl;
	dfs(t.LeftTree());
	dfs(t.RightTree());;
}
int main(){
	tree<int> t;
	t.Create();
	dfs(t);
	return 0;
}
