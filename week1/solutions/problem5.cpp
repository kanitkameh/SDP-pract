#include <iostream>
#include <fstream>

using namespace std;

struct Person {
  char name[32];
  int age;
};

int main() {
  char fileName[64];
  cin >> fileName;
  
  int ageRestriction = 10;
  ifstream fin(fileName, ios::binary);

  while(!fin.eof()) {
    Person p;
    fin.read((char*) &p, sizeof(p));
    if(p.age == ageRestriction) {
      cout << p.name << endl;
    }
  }

  return 0;
}