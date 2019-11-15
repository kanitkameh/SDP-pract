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
      return VectorIterator<T>(0, data);
    }
    VectorIterator<T> end() {
      return VectorIterator<T>(size, data);
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

        int current;
        T *array;

        VectorIterator(int start, T *array)
          : current(start), array(array)
        {};

      public:
        T &operator*() {
          return array[current];
        }
        bool operator == (const VectorIterator<T> &it) const {
          return current == it.current;
        }
        bool operator != (const VectorIterator<T> &it) const {
          return current != it.current;
        }
        VectorIterator<T> &operator++() {
          current++;
          return *this;
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