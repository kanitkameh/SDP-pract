#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct Person {
  char name[32];
  int age;
};

int main() {
  char fileName[32];

  cin >> fileName;

  ifstream fin(fileName, ios::binary | ios::in);
  vector<Person> people;
  
  while(!fin.eof()) {
    Person p;
    fin.read((char*) &p, sizeof(p));
    people.push_back(p);
  }
  fin.close();

  for(int i = 0; i < people.size() - 1; i++) {
    for(int j = i + 1; j < people.size(); j++) {
      if( strcmp(people[j].name, people[i].name) < 0 ) {
        swap(people[i], people[j]);
      }
    }
  }

  ofstream fout(fileName, ios::binary | ios::out);

  for(int i = 0; i < people.size(); i++) {
    fout.write((char*) &(people[i]), sizeof(Person));
  }

  fout.close();

  return 0;
}