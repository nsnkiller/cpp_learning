#include <memory>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


void f_1() {
    // Example of a function that does nothing
    cout << "----------------------------------------" << endl << "Function f_1 called" << endl;
    // Example of memory management using smart pointers
    vector<shared_ptr<int>> vec;
    
    for (int i = 0; i < 5; ++i) {
        vec.push_back(make_shared<int>(i * 10));
    }
    
    cout << "Vector elements: ";
    for (const auto& item : vec) {
        cout << *item << " ";
    }
    cout << endl;

    // Shared pointer example
    shared_ptr<int> sp1 = make_shared<int>(100);
    shared_ptr<int> sp2 = sp1; // Shared ownership
    cout << "Shared pointer value: " << *sp1 << ", Reference count: " << sp1.use_count() << endl;
    cout << "Function f_1 left" << endl << "----------------------------------------" << endl;
}

void f_2() {
    // Example of a function that does nothing
    cout << "----------------------------------------" << endl << "Function f_2 called" << endl;

    int *p = new int(42);
    int *q = new int(100);
    q = p; // q now points to the same memory as p, but the original memory allocated for q is lost

    auto p2 = make_shared<int>(42);
    auto q2 = make_shared<int>(100);
    q2 = p2; // q2 now shares ownership of the memory with p2

    // This function is intentionally left empty
    cout << "----------------------------------------" << endl << "Function f_2 left" << endl;
}

void f_12_23() {
    // Example of a function that does nothing
    cout << "----------------------------------------" << endl << "Function f_12_23 called" << endl;

    const char *p = "Hello ";
    const char *q = "World!";

    char *r = new char[strlen(p) + strlen(q) + 1];
    strcpy(r, p);
    strcat(r, q);
    cout << "Concatenated string: " << r << endl;

    string s1 = "hello ";
    string s2 = "world!";
    string s3 = s1 + s2;

    strcpy(r, s3.c_str()); // Copy the concatenated string into r
    cout << "Concatenated string using std::string: " << r << endl;

    delete[] r; // Free the allocated memory
    cout << "Memory for concatenated string freed." << endl;


    // This function is intentionally left empty
    cout << "----------------------------------------" << endl << "Function f_12_23 left" << endl;
}


int main() {
    cout << "Memory Management Example" << endl;
    f_1(); // Call the function to demonstrate memory management
    f_2(); // Call the second function
    f_12_23(); // Call the third function
    return 0;
}