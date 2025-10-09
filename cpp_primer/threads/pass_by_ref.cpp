#include <iostream>
#include <thread>
#include <functional>

void test(int& ti) {
   std::cout << "sub thread start" << std::endl;
   ti++;
   std::cout << "sub thread end" << std::endl;
}

int main() {
   int i = 4;
   std::thread t(test, std::ref(i));
   t.join();
   std::cout << "i changed: " << i << std::endl;
   return 0;
}