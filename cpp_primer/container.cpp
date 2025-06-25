#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include <iterator>
#include <array>

using namespace std;

bool FindNumberInVector(const std::vector<int>& vec, int number) {
    for (const auto& item : vec) {
        if (item == number) {
            return true;
        }
    }
    return false;
}

auto FindNumberInVector_by_iterator(const std::vector<int>& vec, int number) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (*it == number) {
            return it;
        }
    }
    return vec.end();
}


void traverseVector(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        // Process item
        cout<< item << " ";
    }
}

void array_example(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {0};
    for (int i = 0; i < 5; ++i) {
        arr2[i] = arr[i];
    }

    array<int, 5> myArray = {1, 2, 3, 4, 5};
    array<int, 5> myArray2 = myArray;

    for (const auto& item : myArray2) {
        cout << item << " ";
    }
    array<int, 5> myArray3({6, 7, 8, 9, 10});
    cout << endl;
}

void example_9_13(){
    // Example function for 9-13
    std::cout << "Example function 9-13" << std::endl;
    std::list<int> l = {1, 2, 3, 4, 5};
    std::cout << "list elements: ";
    for (const auto& item : l) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    vector<double> vec;
    vec.assign(l.begin(), l.end());
    std::cout << "Vector elements: ";
    for (const auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


void example_9_14() {
    // Example function for 9-14
    std::cout << "Example function 9-14" << std::endl;
    list<char*> charList = {"Hello", "World", "C++"};

    vector<string> strVec;
    strVec.assign(charList.begin(), charList.end());    

    std::cout << "Vector of strings: ";
    for (const auto& str : strVec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

void example_container_comparison(){
    // Example function for container comparison
    std::cout << "Example function for container comparison" << std::endl;
    std::vector<int> vector1 = {1, 2, 3};
    vector<int> vector2 = {1, 2, 3};
    vector<int> vector3 = {1, 2, 3, 4, 5, 6};
    vector<int> vector4 = {1, 2, 4, 4, 5, 6};

    vector1 == vector2 ? std::cout << "vector1 is equal to vector2" << std::endl : std::cout << "vector1 is not equal to vector2" << std::endl;
    vector1 > vector3 ? std::cout << "vector1 is greater than vector3" << std::endl : std::cout << "vector1 is not greater than vector3" << std::endl;
    vector3 > vector4 ? std::cout << "vector3 is greater than vector4" << std::endl : std::cout << "vector3 is not greater than vector4" << std::endl;
}

void example_container_add(){

    cout << "Example of adding elements to containers" << endl;
    vector<string> svec;
    list<string> slist;

    slist.insert(slist.begin(), "Hello");
    slist.insert(slist.end(), "World");

    svec.insert(svec.begin(), "C++");
    svec.insert(svec.end(), "Programming");

    cout << "List elements: ";
    for (const auto& item : slist) {
        cout << item << " ";
    }       

    cout << endl;
    svec.insert(svec.end(), slist.begin(), slist.end());

    svec.insert(svec.begin(), 10, "Anna");

    cout << "Vector elements: ";    
    for (const auto& item : svec) {
        cout << item << " ";
    }
    cout << endl;
}

void example_container_delete() {
    // Example function for deleting elements from containers
    std::cout << "Example function for deleting elements from containers" << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0) { // Delete even numbers
            it = vec.erase(it);
            cout << "Deleted: " << *it << std::endl;
        }else {
            ++it;
        }
    }

    vec.erase(vec.end(), vec.end());
    std::cout << "Vector after deletion: ";
    for (const auto& item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


void example_9_26() {
    // Example function for 9-26
    std::cout << "Example function 9-26" << std::endl;

    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    vector<int> v(ia, ia + sizeof(ia) / sizeof(int));
    list<int> l(ia, ia + sizeof(ia) / sizeof(int));

    auto it = v.begin();
    auto it2 = l.begin();

    while(it != v.end()){
        if(*it % 2 == 0) {
            cout << "Even number in vector: " << *it << endl;
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    while(it2 != l.end()){
        if(*it2 % 2 == 1) {
            cout << "Odd number in list: " << *it2 << endl;
            it2 = l.erase(it2);
        } else {
            ++it2;
        }
    }

    std::cout << "Vector after deletion: ";
    for (const auto& item : v) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
    std::cout << "List after deletion: ";
    for (const auto& item : l) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void example_array() {
    array<int, 5> myArray = {1, 2, 3, 4, 5};
    cout << "\nArray elements: ";
    for (const auto& item : myArray) {
        cout << item << " ";
    }   

    array<int, 5> myArray2 = {42};
    //myArray2.fill(10);
    cout << "\nFilled array elements: ";
    for (const auto& item : myArray2) {
        cout << item << " ";
    }
}

void example_capacity_size(){
    std::vector<int> myVector = {100, 200, 300, 400, 500};
    cout << "Before inserting: Vector capacity: " << myVector.capacity() << endl;
    cout << "Before inserting: Vector size: " << myVector.size() << endl;
    auto iter1 =myVector.begin();
    auto iter2 = myVector.end();
    cout << "Vector elements using iterators: ";
    while(iter1 < iter2) {
        cout << *iter1 << " ";
        ++iter1;
    }
    myVector.insert(myVector.end(), {600, 700, 800});
    cout << "Vector empty: " << (myVector.empty() ? "Yes" : "No") << endl;
    cout << "Vector capacity: " << myVector.capacity() << endl;
    cout << "Vector size: " << myVector.size() << endl;
    cout << "Vector max size: " << myVector.max_size() << endl; 
    cout << "Vector front: " << myVector.front() << endl;
    cout << "Vector back: " << myVector.back() << endl;
    cout << "Vector data: " << *myVector.data() << endl;
    cout << "Vector at(2): " << myVector.at(2) << endl;
    myVector.reserve(20);
    cout << "After reserving: Vector capacity: " << myVector.capacity() << endl;
    cout << "After reserving: Vector size: " << myVector.size() << endl;

    // myVector.shrink_to_fit();
    // cout << "After resizing: Vector size: " << myVector.size() << endl;
    // cout << "After resizing: Vector capacity: " << myVector.capacity() << endl;

    while (myVector.size() != myVector.capacity())
    {
        myVector.push_back(0);
        cout << "Pushed back 0, new size: " << myVector.size() << endl;
        cout << "Pushed back 0, new capacity: " << myVector.capacity() << endl;
    }
    
}

void example_9_39()
{
    vector<int> vec;
    vec.reserve(1024); // Reserve space for 1024 elements
    while (vec.size() < 512) {
        vec.push_back(0); // Fill the vector with zeros
    }

    vec.resize(vec.size() + vec.size()/2);
    cout << "Vector size after resizing: " << vec.size() << endl;
    cout << "Vector capacity after resizing: " << vec.capacity() << endl;
}

void example_string(){
    std::string str = "Hello, World!";
    std::cout << "String length: " << str.length() << std::endl;
    std::cout << "String at(0): " << str.at(0) << std::endl;
    std::cout << "String substr(0, 5): " << str.substr(0, 5) << std::endl;
    std::cout << "String find('o'): " << str.find('o') << std::endl;
    std::cout << "String replace(7, 5, \"C++\"): " << str.replace(7, 5, "C++") << std::endl;
    std::cout << "String after replace: " << str << std::endl;
    std::cout << "String empty: " << (str.empty() ? "Yes" : "No") << std::endl;
    std::cout << "String capacity: " << str.capacity() << std::endl;
}

void example_9_41()
{
    vector<char> charVec = {'H', 'e', 'l', 'l', 'o'};
    string str(charVec.begin(), charVec.end());
    cout << "String created from vector: " << str << endl;

    string str1(charVec.data(), charVec.size());
    cout << "String created from vector data: " << str1 << endl;
}

string & example_9_43(string &s, const string &oldVal, const string &newVal) {
    size_t pos = 0;
    while ((pos = s.find(oldVal, pos)) != string::npos) {
        s.replace(pos, oldVal.length(), newVal);
        pos += newVal.length(); // Move past the new value
    }
    return s;
}

void example_string_find()
{
    std::string str = "Hello, World!";
    std::cout << "String find('o'): " << str.find('o') << std::endl;
    std::cout << "String find('z'): " << str.find('z') << std::endl;

    string numbers("1234567890"), name("r2d2");
    auto pos = name.find_first_of(numbers);
    if (pos != string::npos) {
        cout << "Found a digit in name at position: " << pos << endl;
    } else {
        cout << "No digit found in name" << endl;
    }

    string dept("03741p2");
    pos = dept.find_first_not_of(numbers);
    if (pos != string::npos) {  
        cout << "First non-digit character in dept at position: " << pos << endl;
    } else {
        cout << "All characters in dept are digits" << endl;
    }
}

int main() {
    // List example
    std::list<int> myList = {1, 2, 3, 4, 5};
    myList.push_back(6);
    myList.push_front(0);
    
    // Deque example
    std::deque<int> myDeque = {10, 20, 30};
    myDeque.push_back(40);
    myDeque.push_front(5);

    // Vector example
    std::vector<int> myVector = {100, 200, 300};
    myVector.push_back(400);
    myVector.insert(myVector.begin() + 1, 150);
    myVector.erase(myVector.begin() + 2);
    traverseVector(myVector);
    cout << endl;

    cout << "Found 200: " << (FindNumberInVector(myVector, 200) ? "Yes" : "No") << endl;

    cout << "Found 300: " << (FindNumberInVector(myVector, 300) ? "Yes" : "No") << endl;

    cout << "Found 150: " << (FindNumberInVector_by_iterator(myVector, 150) != myVector.end() ? "Yes" : "No") << endl;
    cout << "Found 500: " << (FindNumberInVector_by_iterator(myVector, 500) != myVector.end() ? "Yes" : "No") << endl;

    auto it = FindNumberInVector_by_iterator(myVector, 400);
    if (it != myVector.end()) {
        cout << "Found 400 at position: " << it - myVector.begin()<< endl;
    } else {
        cout << "400 not found" << endl;
    }

    example_array();

    array_example();

    example_9_13();

    example_9_14();

    example_container_comparison();

    example_container_add();

    example_container_delete();

    example_9_26();

    example_capacity_size();

    example_9_39();

    example_string();

    example_9_41();

    string s = "tho, thru, tho";
    string s1 = example_9_43(s, "tho", "though");
    cout << "String after replacement: " << s1 << endl;

    example_string_find();

    cout << endl;
    return 0;
}