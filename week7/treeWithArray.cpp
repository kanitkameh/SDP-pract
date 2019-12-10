#include <iostream>
#include <stack>
#include "tree.cpp"

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int value) {
    data = value;
  }
};

void printTree(int tr[], int n, int currPos) {
  if(currPos >= n || tr[currPos] == -1) {
    return;
  }

  cout << tr[currPos] << " ";
  printTree(tr, n, currPos * 2 + 1);
  printTree(tr, n, currPos * 2 + 2);
}

int main() {
  int tr[5] = { 1, 3, 2, 4, 5 };

  printTree(tr, 5, 0);

  tree<int> t;
  t.CreateWithArr(tr, 5);
  t.getRoot();
  
  return 0;
}

// simple tests
// 1 y 2 n n y 3 n n