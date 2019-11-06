#include <vector>
#include <iostream>

template <class T>
class LListIterator;

template <class T>
class LList{
  private:
    std::vector<T> data;
    int size;
    int offset; 

  public:
    friend class LListIterator<T>;
    LListIterator<T> begin() {
      //TODO
    }
    LListIterator<T> end() {
      //TODO
    }

    LList() : size(0), offset(0) {}

    void insertAt(T element, int position){
      for(int i = position; position > 0; position--) {
        data[size - position] = data[size - position - 1];
      }
    }

    T& getElementAt(int position) {
      return data[size - position - 1];
    }
    int getSize() {
      return size;
    }
};

template <class T>
class LListIterator {
  private:

    LListIterator() {};
    //variables

  public:
    friend class LList<T>;
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
  LList<int> a;
  a.insertAt(1,0);
  a.insertAt(1,0);
  a.insertAt(1,0);
  a.insertAt(1,0);
  for(auto i = a.begin(); i != a.end(); ++i) {
    std::cout << *i;
  }

  return 0;
}