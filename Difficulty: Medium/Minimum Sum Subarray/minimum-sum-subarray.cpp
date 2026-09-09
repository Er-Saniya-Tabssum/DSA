class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int best_ending =0;
        int sum=INT_MAX;
        for(int i=0;i<arr.size();i++){
            int v1=arr[i];
            int v2=best_ending+arr[i];
            best_ending = min(v1,v2);
            sum=min(best_ending,sum);
        }
        return sum;
    }
};