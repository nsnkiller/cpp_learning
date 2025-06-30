#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <cstring>


using namespace std;

void f_10_3(){
    vector<int> v = {1, 2, 3, 4, 5};

    auto s = accumulate(v.begin(), v.end(), 0);

    cout << "Sum of elements in vector: " << s << endl;
}

void f_10_5(){
    char* p[] = {"Hello", "World", "C++"};
    char* q[] = {strdup(p[0]), strdup(p[1]), strdup(p[2])};
    char* r[] = {p[0], p[1], p[2]};

    cout << equal(begin(p), end(p), q) << endl; // false
    cout << equal(begin(p), end(p), r) << endl; // true
}

void fill_vector() {
    vector<int> v(10);
    int value = 5; // Value to fill the vector with
    fill(v.begin(), v.end(), value);
    cout << "Filled vector: ";
    for (const auto& item : v) {    
        cout << item << " ";
    }
    cout << endl;

    fill(v.begin(), v.begin() + 5, 10); // Fill first 5 elements with 10
    cout << "Partially filled vector: ";
    for (const auto& item : v) {    
        cout << item << " ";
    }
    cout << endl;   
}

void f_replace(){
    vector<int> v = {1, 2, 3, 4, 5, 3, 4, 5, 6, 7, 8, 9};
    replace(v.begin(), v.end(), 3, 10); // Replace all occurrences of 3 with 10
    cout << "Vector after replace: ";
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;

    // Using replace_copy to create a new vector with replaced values
    vector<int> new_v;
    replace_copy(v.begin(), v.end(), back_inserter(new_v), 10, 20); // Replace 10 with 20 in output
    cout << "New vector after replace_copy: ";
    for (const auto& item : new_v) {    
        cout << item << " ";
    }   
    cout << endl;
    // Using replace_if to replace elements that satisfy a condition
    replace_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }, 0); // Replace even numbers with 0
    cout << "Vector after replace_if: ";
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;
}


void elim_dups() {
    list<string> lst = {string("apple"), string("banana"), string("apple"), string("orange"), string("banana"), string("kiwi")};
    // Sort the list to prepare for unique operation
    for (const auto& item : lst) {
        cout << item << " ";
    }
    cout << endl;
    // Remove duplicates
    lst.sort();
    lst.unique();
    cout << "List after removing duplicates: ";
    for (const auto& item : lst) {  
        cout << item << " ";
    }   
    cout << endl;
    // Using unique_copy to create a new list with unique elements
    vector<string> unique_vec;
    unique_copy(lst.begin(), lst.end(), back_inserter(unique_vec));
    cout << "Unique elements: ";
    for (const auto& item : unique_vec) {
        cout << item << " ";
    }
    cout << endl;


    auto is_shorter = [](const string& a, const string& b) {
        return a.size() < b.size();
    };

    sort(unique_vec.begin(), unique_vec.end(), is_shorter); // Sort by size of strings
    cout << "Sorted unique elements by size: ";
    for (const auto& item : unique_vec) {
        cout << item << " ";
    }
    cout << endl;

    // using algorithm to remove duplicates from a vector
    list<string> lst2 = {string("apple"), string("banana"), string("apple"), string("orange"), string("banana"), string("kiwi")};
    lst2.sort(); // Sort the list to prepare for unique operation
    lst2.erase(unique(lst2.begin(), lst2.end()), lst2.end()); // Remove duplicates
    cout << "List after removing duplicates: ";
    for (const auto& item : lst2) {
        cout << item << " ";
    }   
    cout << endl;
}


void f_iter()
{
    list<int> lst = {1, 2, 3, 4, 5};
    list<int> lst2, lst3;

    copy(lst.cbegin(), lst.cend(), front_inserter(lst2)); // Copy elements to lst2
    cout << "List after front_inserter: ";
    for (const auto& item : lst2) {
        cout << item << " ";
    }
    cout << endl;
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin())); // Copy elements to lst3
    cout << "List after inserter: ";
    for (const auto& item : lst3) {
        cout << item << " ";
    }
    cout << endl;
}


void f_10_27()
{
    vector<int> ivec = {1, 1, 2, 3, 4, 4, 5, 6, 6, 7};

    list<int> ilst;

    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));

    cout << "List after unique copy: ";
    for (const auto& item: ilst){
        cout << item << " ";
    }
    cout << endl;
}

void f_10_28()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};

    list<int> lst1, lst2, lst3;

    copy(ivec.begin(), ivec.end(), inserter(lst1, lst1.begin()));

    copy(ivec.begin(), ivec.end(), back_inserter(lst2));

    copy(ivec.begin(), ivec.end(), front_inserter(lst3));

    cout << "lst1 after inserter: ";
    for (const auto & item: lst1){
        cout << item << " ";
    }
    cout << endl;

    cout << "lst2 after back_inserter: ";
    for (const auto & item: lst2){
        cout << item << " ";
    }
    cout << endl;

    cout << "lst3 after back_inserter: ";
    for (const auto & item: lst3){
        cout << item << " ";
    }
    cout << endl;

}

void reverse_vector()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9,10};

    //reverse(ivec.begin(), ivec.end());

    for (auto iter = ivec.rbegin(); iter != ivec.rend(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    sort(ivec.rbegin(), ivec.rend());
    for( const auto & item: ivec){
        cout << item << " ";
    }
    cout << endl;

}


void find_iter()
{
    string line = string("I have a dream at my young age, but right now I don't know if I still have a dream.");

    auto comma = find(line.cbegin(), line.cend(), ',');

    cout << string(line.cbegin(), comma) << endl;

    auto rcomma = find(line.crbegin(), line.crend(), ',');

    cout << string(line.crbegin(), rcomma) << endl;

    cout << string(rcomma.base(), line.cend()) << endl;
}


void f_10_36()
{
    list<int> ilst = {0,1,2,3,4,5,6,7,8,9,0,3,2,1,0,9,8,7,6,5,4,3,2,1};

    auto iter = find(ilst.cbegin(), ilst.cend(), 0);

    if (iter != ilst.cend()) {
        cout << "Found 0 at position: " << distance(ilst.cbegin(), iter) << endl;
    } else {
        cout << "0 not found in the list." << endl;
    }

    auto iter2 = find(ilst.crbegin(), ilst.crend(), 0);

    cout << distance(ilst.cbegin(), iter2.base()) << endl;
}

void f_merge_sort()
{
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8, 10};
    vector<int> merged(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged.begin());

    cout << "Merged vector: ";
    for (const auto& item : merged) {
        cout << item << " ";
    }
    cout << endl;
}

void _f_11_8(vector<int>& v)
{
    // using vector to emulate the behavior of a set
   sort(v.begin(), v.end());
   auto last = unique(v.begin(), v.end());
   v.erase(last, v.end());
}

void f_11_8()
{
    vector<int> v = {1, 2, 3, 4, 5, 3, 4, 5, 6, 7, 8, 9};
    
    v.push_back(7); // Add an element to the end of the vector
    _f_11_8(v); // Remove duplicates
    cout << "Vector after removing duplicates: ";
    for (const auto& item : v) {
        cout << item << " ";
    }
    cout << endl;
}

void f_11_12()
{
    vector<string> v = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape"};
    vector<int> v_lengths;
    vector<pair<string,int>> v_pairs;

    for(const auto& item : v) {
        v_lengths.push_back(item.size()); // Store the lengths of the strings
    }

    for(auto i = 0; i < v.size(); ++i) {
        v_pairs.emplace_back(v[i], v_lengths[i]);
    }

    for(const auto& item : v_pairs) {
        cout << "String: " << item.first << ", Length: " << item.second << endl;
    }
}



int main(){
    vector<int> vec({1, 2, 3, 4, 5, 3, 4, 5, 6, 7, 8, 9});
    auto cnt = count(vec.begin(), vec.end(), 3);
    cout << "Count of 3 in vector: " << cnt << endl;

    f_10_3();

    f_10_5();

    fill_vector();

    f_replace();

    elim_dups();

    f_iter();

    f_10_27();

    f_10_28();

    reverse_vector();

    find_iter();

    f_10_36();

    f_merge_sort();

    f_11_8();

    f_11_12();
    cout << "All operations completed successfully." << endl;
}