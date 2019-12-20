#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

// Това е абстракцията на интерфейса който
// изпълнява команда
class Command {
public:
  virtual void execute(std::vector<std::string> argv) = 0;
};

class EchoCommand : public Command {
// имплементирайре командата тук
};
//
// имплементирайте останалите команди тук... примерно
//

class CommandPattern {
  public:
  std::map<std::string, Command*> commands;

  CommandPattern() {
    //инициализация на структурата с команди
  }
};

// можете да ползвате тази помощна фун12кция за да взимате въведените аргументи
std::vector<std::string> split_string(std::string &str);

int main() {
  //тестов код, че split_string работи
  std::string s("asdf asddf   asdasd  sad");
  std::vector<std::string> argv = split_string(s);
  for (std::string str : argv)
  {
    std::cout << str << std::endl;
  }

  return 0;
}

// това седи долу за да не пречи
std::vector<std::string> split_string(std::string &str) {
  std::vector<std::string> argv;
  std::stringstream str_stream(str);
  std::string tmp;
  while (std::getline(str_stream, tmp, ' ')) {
    if( tmp.compare("") > 0 ) {
      argv.push_back(tmp);
    }
  }
  return argv;
}