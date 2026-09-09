class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int best_ending = 0;
        int sum = INT_MIN;
        int csum = 0;
        int n = nums.size();
        int leastending = 0;
        int leastsum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            csum = csum + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            int v1 = nums[i];
            int v3 = best_ending + nums[i];
            best_ending = max(v1, v3);
            sum = max(sum, best_ending);
        }
        for (int i = 0; i < nums.size(); i++) {
            int v1 = nums[i];
            int v3 = leastending + nums[i];
            leastending = min(v1, v3);
            leastsum = min(leastsum, leastending);
            cout << leastsum << " ";
        }
        if(sum<0){
            return sum;
        }
        cout << csum << " csum : ";
        csum = csum - leastsum;
        return max(sum, csum);
    }
};