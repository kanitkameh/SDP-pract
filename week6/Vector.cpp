#include <vector>
#include <iostream>

template <class T>
class VectorIterator;

template <class T>
class Vector{
  private:
    T *data;
    int size;

  public:
    friend class VectorIterator<T>;

    VectorIterator<T> begin() {
      //TODO
    }
    VectorIterator<T> end() {
      //TODO
    }

    Vector() : size(0) {
      data = new T[64];
    }

    void insertAt(T element, int position){
      for(int i = size; i > position; i--) {
        data[i] = data[i - 1];
      }
      data[position] = element;
      size++;
    }

    void pushBack(T element) {
      data[size++] = element;
    }

    T& getAt(int position) {
      return data[position];
    }
    int getSize() {
      return this->size;
    }

    ~Vector() {
      delete [] data;
    }
};

template <class T>
class VectorIterator {
      private:
        friend class Vector<T>;

        //variables ???

        VectorIterator(/*TODO*/){
          //TODO
        };

      public:
        T &operator*() {
          //TODO
        }
        bool operator == (const VectorIterator<T> &it) const {
          //TODO
        }
        bool operator != (const VectorIterator<T> &it) const {
          //TODO
        }
        VectorIterator<T> &operator++() {
          //TODO
        }
    };

int main() {
  Vector<int> a;
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  a.pushBack(4);

  for(int i = 0; i < 4; i++) {
    std::cout << a.getAt(i) << " ";
  }
  std::cout << std::endl;

  for(VectorIterator<int> it = a.begin(); it != a.end(); ++it){
    std::cout << *it << std::endl;
  }

  return 0;
}