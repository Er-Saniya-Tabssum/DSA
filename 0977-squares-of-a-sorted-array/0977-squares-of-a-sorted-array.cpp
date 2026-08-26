class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp;
        int id = 0;
        int neg = 0;
        while (neg < nums.size() && nums[neg] < 0) {
            temp.push_back(nums[neg] * nums[neg]);
            neg++;
        }
        for (int i = neg; i < nums.size(); i++) {
            ans.push_back(nums[i] * nums[i]);
        }
        int i = 0;
        int j = 0;
        int left=0,right=temp.size()-1;
        while(left<=right){
            int t=temp[left];
            temp[left]=temp[right];
            temp[right]=t;
            left++;
            right--;
        }
        while (i < temp.size() && j < ans.size()) {
            if (temp[i] <= ans[j]) {
                nums[id] = temp[i];
                id++;
                i++;
            }
            else {
                nums[id] = ans[j];
                id++;
                j++;
            }
        }
        while (i < temp.size()) {
            nums[id] = temp[i];
            id++;
            i++;
        }
        while (j < ans.size()) {
            nums[id] = ans[j];
            id++;
            j++;
        }
        return nums;
    }
};