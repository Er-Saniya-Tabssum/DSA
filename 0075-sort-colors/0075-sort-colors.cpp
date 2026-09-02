class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int low=0;
        int high=nums.size() - 1;
        while (i <= high) {
            if (nums[i] == 0) {
                int temp = nums[i];
                nums[i] = nums[low];
                nums[low] = temp;
                i++;
                low++;
            } 
            else if (nums[i] == 1) {
                i++;
            } 
            else if (nums[i] == 2) {
                int temp = nums[i];
                nums[i] = nums[high];
                nums[high] = temp;
                high--;
            }
        }
    }
};