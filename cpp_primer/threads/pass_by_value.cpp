#include <iostream>
#include <thread>
void test(int ti, int tj) {
   std::cout << "sub thread start" << std::endl;
   std::cout << ti << " " << tj << std::endl;
   std::cout << "sub thread end" << std::endl;
}


int main() {
   int i = 4, j = 5;
   std::thread t(test, i, j);
   t.join();
   return 0;
}