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


// void printTreeArray(int tree[], int n, int current) {
//   if (current >= n) {
//     return;
//   }
//   cout << tree[current] << " ";
//   printTreeArray(tree, n, current * 2 + 1);
//   printTreeArray(tree, n, current * 2 + 2);
// }

int main() {
  int tr\[5] = { 1, 3, 2, 4, 5 };
  // printTreeArray(treee, 5, 1);

  // tree<int> t;
  // t.CreateWithArr(treee, 5);

  // t.print();

  return 0;
}

// simple tests
// 1 y 2 n n y 3 n n