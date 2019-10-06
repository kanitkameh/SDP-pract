#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string line;
  ifstream file("file.txt");

  while(!file.eof()) {
    getline(file, line);
    cout << line << endl;
  }

  file.close();

  return 0;
}