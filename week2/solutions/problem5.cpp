#include <iostream>
#include <stack>w

using namespace std;

int calculateExpr(int a, int b, char op) {
  switch (op)
  {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  }
  return 0;
}

bool isOperation(char symbol) {
  return symbol == '+'
    || symbol == '-'
    || symbol == '*'
    || symbol == '/';
}

int reversePolishNotation(char* str) {
  stack<int> st;

  while(*str) {
    if(isOperation(*str)) {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      st.push(calculateExpr(a, b, *str));
    } else {
      st.push(*str - '0');
    }
    str++;
  }
  return st.top();
}

int main() {
  char str[256];
  cin >> str;
  cout << reversePolishNotation(str) << endl;

 	return 0;
}
