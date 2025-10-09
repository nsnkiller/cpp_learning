#include <iostream>
#include <thread>
using namespace std;

class A {
public:
   int ai;
   A(int i) : ai(i) {
       std::cout << this_thread::get_id() << " construct " << this << std::endl;
   }
   A(const A& a) : ai(a.ai) {
       std::cout << this_thread::get_id() << " copy construct " << this << std::endl;
   }
   ~A() {
       std::cout << this_thread::get_id() << " destruct " << this << std::endl;
   }
};

void test(const A& a) {
   std::cout << this_thread::get_id() << " sub thread start" << std::endl;
   std::cout << this_thread::get_id() << " sub thread end" << std::endl;
}
int main() {
   std::thread t(test, A(4));
   t.join();
   return 0;
}