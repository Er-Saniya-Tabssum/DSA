class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0;
        int one=0;
        int res=0;
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else one++;
            int diff=zero-one;
            if(f.find(diff)==f.end()){
                f[diff]=i;
            }
            else{
                int len = i- f[diff];
                res=max(res,len);
            }
            if(diff==0){
                int len =i+1;
                res = max(len,res);
            }
        }
    return res;
    }
};