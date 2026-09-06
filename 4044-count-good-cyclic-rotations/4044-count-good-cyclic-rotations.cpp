class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long total = 0;
        for (int x : nums)
            total += x;
        long long firstHalf = 0;
        for (int i = 0; i < half; i++)
            firstHalf += nums[i];

        int ans = 0;

        for (int start = 0; start < n; start++) {
            long long secondHalf = total - firstHalf;

            if (firstHalf > secondHalf)
                ans++;

            firstHalf -= nums[start];
            firstHalf += nums[(start + half) % n];
        }

        return ans;
    }
};