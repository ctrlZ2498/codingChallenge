/*
1.Two Sum

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
*/

--------- my solution ----------
  
  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(auto it=nums.begin();it!=nums.end();++it){
            int find = target - *it;
            auto it1 = std::find(it+1, nums.end(), find);
            if(it1!=nums.end()){
                int x =distance(nums.begin(),it1);
                int i =distance(nums.begin(),it);
                ans.assign({i,x});
                break;
            }
        }
        return ans;
    }
};

--------- best solution in discussions ----------
  
  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap ;
         for(int i = 0 ; i < nums.size(); i++) {       
            if(umap[target - nums[i]]) {
                 return {umap[target- nums[i]] -1, i};  // set i back with i-1
            }
            umap[nums[i]] = i+1; // to negate 0 check as false;
         }
     return {};   
    }
};
