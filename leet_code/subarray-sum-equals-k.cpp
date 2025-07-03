#include <vector>
#include <iostream>

using namespace std;

 int subarraySum(vector<int>& nums, int k) {
    int cnt = 0;
    int size = nums.size();
    for (auto i = 0; i < size; i++){
        int sum = 0;
        for (auto j = i; j < size; j++){
            sum += nums[j];
            if (sum == k){
                cnt++;
                // break;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;

    nums = {1, 2, 3};
    k = 3;
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;

    nums = {1,-1,0};
    k = 0; 
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;

     nums = {6,4,3,1};
    k = 0; 
    cout << "Number of subarrays with sum " << k << ": " << subarraySum(nums, k) << endl;

    return 0;
}