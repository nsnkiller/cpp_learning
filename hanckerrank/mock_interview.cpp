
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



/*
 * Complete the 'getRemovableIndices' function below.
 *
 * Given two strings, str1, and str2, where str1 contains exactly one character more than str2, 
 * find the indices of the characters in str1 that can be removed to make str1 equal to str2. 
 * Return the array of indices in increasing order. If it is not possible, return the array [-1]. 
 * * Note: The indices are 0-based.
 * 
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING str1
 *  2. STRING str2
 */

 /*
vector<int> getRemovableIndices(string str1, string str2) {
    int diff_index = -1;
    vector<int> vi;
    if (str1.size() - str2.size() != 1){
        vi.push_back(-1);
        return vi;
    }
    

    string str = str1;
    for(auto i = 0; i < str2.size(); i++){
        if (str1[i] != str2[i]){
            diff_index = i;
            if (str.erase(i) != str2){
                vi.push_back(-1);
                return vi;
            }
            break;
        }
    }
    
    if (diff_index == -1 ){
        diff_index = str1.size() - 1;
    }
    vi.push_back(diff_index);
    int temp_index = diff_index;
    
    while (temp_index - 1 > 0){
        if (str1[temp_index - 1] != str1[diff_index]){
            break;
        }else{
            vi.push_back(temp_index - 1);
            temp_index--;
        }
    }
    
    while (temp_index + 1 <= str1.size()){
        if (str1[temp_index + 1] != str1[diff_index]){
            break;
        }else{
            vi.push_back(temp_index + 1);
            temp_index++;
        }
    }
    sort(vi.begin(), vi.end());
    return vi;
}
    */
vector<int> getRemovableIndices(string str1, string str2) {
    vector<int> indices;
    if (str1.size() - str2.size() != 1) {
        indices.push_back(-1);
        return indices;
    }

    // for (size_t i = 0; i < str1.size(); ++i) {
    //     string modifiedStr = str1.substr(0, i) + str1.substr(i + 1);
    //     if (modifiedStr == str2) {
    //         indices.push_back(i);
    //     }
    // }
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1.compare(0, i, str2, 0, i) == 0 && str1.compare(i + 1, str1.size() - i - 1, str2, i, str2.size() - i) == 0) {
            indices.push_back(i);
        }
    }

    if (indices.empty()) {
        indices.push_back(-1);
    }

    return indices;
}


int main()
{
    string str1;
    getline(cin, str1);

    string str2;
    getline(cin, str2);

    vector<int> result = getRemovableIndices(str1, str2);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}