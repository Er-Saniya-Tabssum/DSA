class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int best_ending = 0;
        int least_ending = 0;
        int leastsum = INT_MAX;
        int bestsum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {

            int v1 = nums[i];
            int v2 = best_ending + nums[i];
            int v3 = least_ending + nums[i];
            best_ending = max(v1, v2);
            bestsum = max(bestsum, best_ending);
            least_ending = min(v1, v3);
            leastsum = min(leastsum, least_ending);
        }
        return max(abs(bestsum), abs(leastsum));
        ;
    }
};