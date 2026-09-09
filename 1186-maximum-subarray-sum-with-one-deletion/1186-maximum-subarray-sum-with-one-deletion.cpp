class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size()==1){
            return arr[0];
        }
        int best_ending=arr[0];
        int nodelete=arr[0];
         int onedelete=INT_MIN;
        int result=INT_MIN;
        for(int i=1;i<arr.size();i++){
            int previous = nodelete;
            int previous2 = onedelete;
            nodelete=max(nodelete+arr[i],arr[i]);
            int v2;
            if(previous2==INT_MIN){
                v2=arr[i];
            }
            else{
                v2 = previous2+arr[i];
            }
            onedelete = max(v2,previous);
            result = max(result,max(onedelete,nodelete));
        }
        return result;
    }
};