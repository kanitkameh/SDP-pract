#include <iostream>

using namespace std;

struct Node {
  int data;
  Node * next;
public:
  Node(){
    data = 0;
    next = nullptr;
  }
};

class List {
  Node * start;
  Node * getNodeAt(int position){
    Node * current = start;
    for(int i=0;i<position;i++){
      current = current->next;
    }
    return current;
  }
public:
  List(){
    start = nullptr;
  }
  void deleteAt(int position){
    if(position==0){
        Node * toDelete = start;
        start = start->next;
        delete toDelete;
    }else{
        Node * prev = getNodeAt(position-1);
        Node * toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }
  }
  void addAt(int element, int position){
    if(position==0){
      Node * toAdd = new Node();
      toAdd->data = element;
      toAdd->next = start;
      start = toAdd;
    }else{
      Node * current = getNodeAt(position-1);
      Node * toAdd = new Node();
      toAdd->data = element;
      toAdd->next = current->next;
      current->next = toAdd;
    }
  }
  int getElementAt(int position){
    return getNodeAt(position)->data;
  }

  void swapEl(int a, int b) {
    
  }

  ~List(){
    while(start!=nullptr){
      Node * toDelete = start;
      start = start->next;
      delete toDelete;
    }
  }
};

int main() {
  List l;
  l.addAt(21,0);
  l.addAt(42,1);
  l.addAt(55,2);
  l.addAt(66,3);
  l.deleteAt(2);
  cout << l.getElementAt(1) << endl;
  cout << l.getElementAt(2) << endl;
  return 0;
}
