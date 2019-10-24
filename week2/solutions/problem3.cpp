#include <iostream>
#include <stack>

using namespace std;

bool isOperation(char symbol) {
  return symbol == '+'
    || symbol == '-'
    || symbol == '*'
    || symbol == '/';
}

bool isIncorrect(char* str) {
  stack<bool> st;
  st.push(true);

  while(*str) {
    if(isOperation(*str)) {
      st.pop();
      st.push(true);
    } else
    if(*str == '(') {
      st.push(false);
    } else
    if(*str == ')') {
      if(st.top() == false) {
        return true;
      }
      st.pop();
    }
    str++;
  }
  return false;
}

int main(){
  char str[256];
  cin >> str;
  cout << isIncorrect(str);

	return 0;
}
