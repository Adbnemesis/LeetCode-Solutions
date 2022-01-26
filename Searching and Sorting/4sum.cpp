class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<nums.size();i++){
            if(i != 0 and nums[i] == nums[i-1])continue;
            for(int j = i+1;j<nums.size();j++){
                if(j!=i+1 and nums[j] == nums[j-1])continue;
            int s = j+1;
            int e = nums.size()-1;
            while(s<e){
                if(nums[i]+nums[s]+nums[e]+nums[j] - target == 0){
                    vector<int> help = {nums[i],nums[s],nums[e],nums[j]};
                    ans.push_back(help);
                    while(s<e and (nums[s] == help[1]))s++;
                    while(s<e and (nums[e] == help[2]))e--;
                }else if(nums[i]+nums[s]+nums[e]+nums[j] < target)s++;
                else e--;
            }
        }
        }
        return ans;
        
    }
};
