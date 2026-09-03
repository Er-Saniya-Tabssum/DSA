class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int length =INT_MAX;
        int cm=length;
        int sum=0;
        while(high < nums.size()){
            sum += nums[high];
            while(sum>=target){
                int temp=high-low+1;
                length=min(temp,length);
                sum -= nums[low];
                low++;
                continue;
            }
                high++;
        }
        if(cm==length){
            length=0;
        }
        return length;
    }
};