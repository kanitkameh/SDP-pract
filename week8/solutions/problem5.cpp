#include <iostream>
#include "tree.cpp"
#include <set>
using namespace std;
bool iterate(tree<int> t,set<int>& s){
	if(t.empty()){
		return false;
	}
	if(s.count(t.RootTree())){
		return true;
	}
	s.insert(t.RootTree());
	return iterate(t.LeftTree(),s) || iterate(t.RightTree(),s);;
}
bool hasDuplicates(tree<int> t){
	set<int> s;
	return iterate(t,s);
}
int main(){
	tree<int> t;
	t.Create();
	cout << hasDuplicates(t) << endl;
	return 0;
}
