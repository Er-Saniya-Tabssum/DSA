class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> ans;
        long long sum;
        while(i<j){
            sum=numbers[i]+numbers[j];
            if(sum > target){
                sum -= numbers[j];
                j--;
            }
            else if(sum < target ){
                i++;
            }
            else{
                break;
            }
        }
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};