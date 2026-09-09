class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int total = 0;
        int sum = 1;
        while (low < nums.size()) {
            high = low;
            while (high < nums.size()) {
                sum = sum * nums[high];
                high++;
                if(sum >= k){
                    break;
                }
                total++;
            }
            low++;
            sum = 1;
        }
        return total;
    }
};