class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int arr[2] = {0};
        int low = 0;
        int high = 0;
        int ans = 0;
        for (high = 0; high < nums.size(); high++) {
            arr[nums[high]]++;
            int len = high - low + 1;
            int maxcount=arr[1];
            int diff = len - maxcount;
            while (diff > k) {
                arr[nums[low]]--;
                low++;
                len = high - low + 1;
                diff = len - maxcount;
            }
            len = high - low + 1;
            ans = max(len, ans);
        }
        return ans;
    }
};