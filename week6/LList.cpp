#include <iostream>

template <class T>
class LListIterator;

template <class T>
class LList{
  private:
    struct Node{
      T data;
      Node *next;
    };

    Node *first;

    Node *getNodeAt(int position) {
      Node *current = first;
      for(int i = 0; i < position; i++){
        current = current->next;
      }
      return current;
    }

  public:
    friend class LListIterator<T>;
    LListIterator<T> begin() {
      //TODO
    }
    LListIterator<T> end() {
      //TODO
    }
    

    LList() : first(nullptr) {}

    void insertAt(T element, int position){
      if(position == 0){
        Node *toAdd = new Node();
        toAdd->data = element;
        toAdd->next = first;
        first = toAdd;
      }else{
        Node *current = getNodeAt(position-1);
        Node *toAdd = new Node();
        toAdd->data = element;
        toAdd->next = current->next;
        current->next = toAdd;
      }
    }

    T& getElementAt(int position){
      return getNodeAt(position)->data;
    }

    ~LList(){
      while(first != nullptr){
        Node *toDelete = first;
        first = first->next;
        delete toDelete;
      }
    }
};

template <class T>
class LListIterator {
  private:
    friend class LList<T>;

    //variables ???
    
    LListIterator(/*???*/){

    };

  public:
    T &operator*() {
      //TODO
    }
    bool operator == (const LListIterator<T> &it) const {
      //TODO
    }
    bool operator != (const LListIterator<T> &it) const {
      //TODO
    }
    LListIterator<T> &operator++() {
      //TODO
    };
};

int main() {

  LList<int> l;
  l.insertAt(1, 0);
  l.insertAt(2, 0);
  l.insertAt(3, 0);
  l.insertAt(4, 0);

  for(auto it = l.begin(); it != l.end(); ++it){
    std::cout << *it << std::endl;
  }

  for(int x : l) {
    std::cout << x << std::endl;
  }

  return 0;
}