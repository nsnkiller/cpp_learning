#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    vector<int> result;
    int pLength = p.size();
    sort(p.begin(), p.end());

    for (int i = 0; i <= s.size() - pLength; i++) {
        string sub = s.substr(i, pLength);
        sort(sub.begin(), sub.end());
        if (sub == p) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    // string s = "cbaebabacd";
    // string p = "abc";
    // string s = "abab";
    // string p = "ab";

    string s = "baa";
    string p = "aa";
    cout << "Input string: " << s << ", Pattern: " << p << endl;
    cout << "Anagram indices: ";    
    vector<int> result = findAnagrams(s, p);
    
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}  