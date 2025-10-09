#include <iostream>
#include <thread>
#include <functional>

void test(char* p) {
   std::cout << "sub thread start" << std::endl;
   std::cout << p << std::endl;
   std::cout << "sub thread end" << std::endl;
}

int main() {
   char s[] = "hello";
   std::thread t(test, s);
   t.join();
   if (t.joinable()) {
      t.join();
   }
   else {
      std::cout << "thread is not joinable" << std::endl;
   }

   return 0;
}