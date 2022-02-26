#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity O(N^2)
vector<int> naive_twoSum(vector<int>& nums, int target) {

    vector<int> result;

    for (auto i = 0; i < nums.size(); i++)
    {
        for (auto j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
            }
        }
    }

    return result;

}

// Time complexity O(N)
vector<int> fast_twoSum(vector<int>& nums, int target) {

    // The key values is the number and the index is the value
    unordered_map<int, int> hash;
    vector<int> result;

    //store the vector in the hash
    for (auto i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }

    for (auto i = 0; i < nums.size(); i++)
    {
        auto number_to_find = target - nums[i];

        if (hash.find(number_to_find) != hash.end()) // look up O(1)
        {
            // it should not be same number; ex: [3,2,4] and 6
            if (i != hash[number_to_find])
            {
                // need to return the indices
                result.push_back(hash[number_to_find]);
                result.push_back(i);

                return result;
            }
        }
    }

    return result;
}


int main()
{
    vector<int> v1 = { 2,7,11,15 };
    auto result = naive_twoSum(v1, 9);
    for (auto i : result)
        cout << i << " ";

    return 0;
}


/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 */
