#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    set<char> charSet;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); ++right) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    //string s = "abcabcbb";
    string s = "abcbdac";
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}