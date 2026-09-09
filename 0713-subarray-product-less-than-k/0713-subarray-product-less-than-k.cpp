class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int total = 0;
        if(k<=1){
            return 0;
        }
        long long product=1;
        for(high=0;high<nums.size();high++){
            product = product * nums[high];
            while(product>=k){
                product /= nums[low];
                low++;
            }
             total += high -low+1;
        }
        return total;
    }
};