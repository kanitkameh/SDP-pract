#include<iostream>
#include"tree.cpp"
using namespace std;
bool contains(tree<int> t1, int element){
		if(t1.empty()){
			return false;
		}
		return t1.RootTree()==element
			||contains(t1.LeftTree(),element)
			||contains(t1.RightTree(),element);
}
int main(){
	tree<int> t1;
	t1.Create();
	int element;
	cout << "What element do you want to search for?" << endl;
	cin >> element;
	cout << contains(t1, element);
	return 0;
}
