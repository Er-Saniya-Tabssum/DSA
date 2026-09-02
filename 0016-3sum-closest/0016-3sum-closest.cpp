class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i=0;i<nums.size()-2;i++){
            int left= i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                int new_diff = abs(sum-target);
                if(new_diff < diff){
                    diff=new_diff;
                    ans=sum;
                }
                if(sum >target) right--;
                else left++;
            }
        }
        return ans;

    }
};