#include <iostream>
#include <fstream>

using namespace std;

struct Person {
  char name[32];
  int age;
};

int main() {
  char fileName[64];
  int n;
  cin >> fileName >> n;
  
  ofstream fout(fileName);

  for(int i = 0; i < n; i++) {
    Person p;
    cin >> p.name >> p.age;
    fout << p.name << " " << p.age << endl;
  }

  fout.close();

  return 0;
}