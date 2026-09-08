class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = nums[0];
        int best_ending=nums[0];
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=best_ending * nums[i];
            int v2 = nums[i];
            int v3 =mini * nums[i];
            best_ending=max(v1,max(v2,v3));
            mini=min(v1,min(v2,v3));
            best_ending = max(best_ending,mini);
            product=max(product,best_ending);
        }
        return product;
    }
};