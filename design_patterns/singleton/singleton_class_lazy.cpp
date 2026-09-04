#include <iostream>
#include <mutex>

class Singleton {
private:
  Singleton() {
    std::cout << "Singleton constructor called, new object created\n";
  }

  static Singleton *firstInstance;
  static std::mutex mtx;

public:
  static Singleton *getInstance() {
    if (!firstInstance) {
      std::lock_guard<std::mutex> lock(mtx); // lock for thread safety
      // multiple threads got into this block but one creates, rest should know that
      if (!firstInstance)          // double locking
        firstInstance = new Singleton();
    }
    return firstInstance;
  }
};

Singleton *Singleton::firstInstance = nullptr;
std::mutex Singleton::mtx;


int main(void) {
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();

  std::cout << (s1 == s2) << '\n';

  return 0;
}
