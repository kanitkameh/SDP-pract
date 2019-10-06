#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Person {
  char name[32];
  int age;
};

int main() {
  char fileName[32];
  char searchName[32];
  char newName[32];

  cin >> fileName;
  cin >> searchName;
  cin >> newName;

  fstream file(fileName, ios::binary | ios::out | ios::in);
  Person p;
  
  while(!file.eof() && strcmp(p.name, searchName) != 0) {
    file.read((char*) &p, sizeof(p));
  }

  strcpy(p.name, newName);
  file.seekp(sizeof(p) * -1, ios::cur);
  file.write((char*) &p, sizeof(p));

  file.close();

  return 0;
}