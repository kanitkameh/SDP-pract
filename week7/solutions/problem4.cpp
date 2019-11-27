#include<iostream>
#include"tree.cpp"
using namespace std;
node<int> * getTreeWithRootGivenElem(node<int>* node, int element){
	if(node==NULL){
		return node;
	}
	if(node->inf==element){
		return node;
	}else if(element<node->inf){
		return getTreeWithRootGivenElem(node->Left,element);
	}else{
		return getTreeWithRootGivenElem(node->Right,element);
	}
}
node<int>* getBiggestElement(node<int>* node){
	while(node->Right!=NULL){
		node=node->Right;
	}
	return node;

}
node<int>* getSmallestElement(node<int>* node){
	while(node->Left!=NULL){
		node=node->Left;
	}
	return node;
}
void deleteLeaf(node<int>* node){
	if(node->Parent!=NULL){
		if(node->Parent->Left==node){
			node->Parent->Left=NULL;
		}else if(node->Parent->Right==node){
			node->Parent->Right=NULL;	
		}
	}
	delete node;
}
void deleteElement(node<int>* root, int element){
	node<int> * elementNode = getTreeWithRootGivenElem(root,element);
	if(elementNode->Left!=NULL){
		node<int> * biggestNode = getBiggestElement(elementNode->Left);
		swap(elementNode->inf,biggestNode->inf);
		deleteLeaf(biggestNode);
	}else if(elementNode->Right!=NULL){
		node<int> * smallestNode = getSmallestElement(elementNode->Right);
		swap(elementNode->inf,smallestNode->inf);
		deleteLeaf(smallestNode);
	}else{
		deleteLeaf(elementNode);		
	}
}
int main(){
	tree<int> t;
	int element;
	t.Create();
	cout << "Enter element value to delete:" << endl;
	cin >> element;
	deleteElement(t.getRoot(),element);
	t.print();
	return 0; 
}
