#include <iostream>

class Singleton {
private:
  Singleton() {
    std::cout << "Singleton constructor called, new object created\n";
  }
  static Singleton *firstInstance;

public:
  static Singleton *getInstance() {
    return firstInstance;
  }
};

Singleton *Singleton::firstInstance = new Singleton();


int main(void) {
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();

  std::cout << (s1 == s2) << '\n';

  return 0;
}
