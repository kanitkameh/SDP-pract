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
      return LListIterator<T>(first);
    }
    LListIterator<T> end() {
      return LListIterator<T>(nullptr);
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

    LListIterator(typename LList<T>::Node *start) : current(start) {};
    typename LList<T>::Node *current;

  public:
    T &operator*() {
      return current->data;
    }
    bool operator == (const LListIterator<T> &it) const {
      return current == it.current;
    }
    bool operator != (const LListIterator<T> &it) const {
      return current != it.current;
    }
    LListIterator<T> &operator++() {
      current = current->next;
      return *this;
    };
};

int main() {

  LList<int> l;
  l.insertAt(1, 0);
  l.insertAt(2, 0);
  l.insertAt(3, 0);
  l.insertAt(4, 0);

  for(int x : l) {
    std::cout << x << std::endl;
  }

  return 0;
}