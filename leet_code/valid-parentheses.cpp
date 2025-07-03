#include <map>
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;


bool isValid(string s) 
{
    map<char, char> smap;
    smap[')'] = '(';
    smap[']'] = '[';
    smap['}'] = '{';

    stack<char> sc;
    for (auto i = s.begin(); i != s.end(); i++){
        // cout << *i << " " <<  endl;
        if ((*i == '(') || (*i == '[') || (*i == '{')){
            sc.push(*i);
            // cout << "top: " << sc.top() << " " << endl;
        } else if (sc.size() == 0 || smap[*i] != sc.top()){
            //cout << "smap: " << smap[*i] << " top: " << sc.top() << endl;
            return false;
        } else {
            sc.pop();
        }
    }
    if (sc.size() == 0)
        return true; 
    else
        return false; 
}

void map_test()
{
    isValid("()[]{}") ? cout << "Valid" << endl : cout << "Invalid" << endl;
    isValid("((") ? cout << "Valid" << endl : cout << "Invalid" << endl;
    isValid("(}") ? cout << "Valid" << endl : cout << "Invalid" << endl;
    isValid("}(") ? cout << "Valid" << endl : cout << "Invalid" << endl;
}

int main(){
    map_test();
    return 0;
}
    