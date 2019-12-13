#include <iostream>
#include <vector>

using namespace std;

void insert_heap(int heap[], int &n, int x) {
  heap[n++] = x;

  int node_i = n - 1;
  int parent_i = (n - 2) / 2;
  while(parent_i >= 0 && heap[node_i] > heap[parent_i]) {
    swap(heap[node_i], heap[parent_i]);
    node_i = parent_i;
    parent_i = (parent_i - 1) / 2;
  }
}

void heapify(int heap[], int n, int root) {
  int largest = root;
  int left = root * 2 + 1;
  int right = root * 2 + 2;
  if(left < n && heap[largest] < heap[left]) {
    largest = left;
  }
  if(right < n && heap[largest] < heap[right]) {
    largest = right;
  }
  if(largest != root) {
    swap(heap[largest], heap[root]);
    heapify(heap, n, largest);
  }
}

void delete_heap(int heap[], int &n, int x) {
  int deleted_i = 0;
  for(int i = 0; i < n; i++) {
    if(heap[i] == x) {
      heap[i] = heap[--n];
      heapify(heap, n, i);
      return;
    }
  }
}

int main() {
  int heap[64];
  int n = 0;

  insert_heap(heap, n, 10);
  insert_heap(heap, n, 6);
  insert_heap(heap, n, 9);
  insert_heap(heap, n, 11);
  insert_heap(heap, n, 66);
  insert_heap(heap, n, 7);
  insert_heap(heap, n, 1);
  insert_heap(heap, n, 33);

  for(int i = 0; i < n; i++) {
    cout << heap[i] << " ";
  }
  cout << endl;
  delete_heap(heap, n, 33);
  for(int i = 0; i < n; i++) {
    cout << heap[i] << " ";
  }
  cout << endl;
  heapsort(heap, n);
  for(int i = 0; i < n; i++) {
    cout << heap[i] << " ";
  } 
  return 0;
}
