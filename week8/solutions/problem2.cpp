#include <iostream>
#include "tree.cpp"
#include <queue>
using namespace std;
void bfs(tree<int> t){
	int level = 0;
	queue<node<int>*> q;
	q.push(nullptr); //splitting element to distinguish different levels
	q.push(t.getRoot());
	while(q.size()>=2 ){
		node<int>* current = q.front();
		q.pop();
		if(current==nullptr){
			level++;
			cout << "\nLevel " << level << " : ";
			q.push(current);
			continue;
		}
		cout << current->inf << " ";
		if(current->Left!=nullptr)
			q.push(current->Left);
		if(current->Right!=nullptr)
			q.push(current->Right);
	}
}
int main(){
	tree<int> t;
	t.Create();
	bfs(t);
	return 0;
}
