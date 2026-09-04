class Solution {
public:
    int find_max(unordered_map<int,int> m){
        int maxi=INT_MIN;
        for(auto it : m){
            maxi=max(it.second,maxi);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int low=0;
        int high=0;
        int ans=INT_MIN;
        unordered_map<int,int> m;
        for(high=0;high<s.size();high++){
            m[s[high]]++;
            int len=high-low+1;
            int maxcount = find_max(m);
            int diff=len-maxcount;
            while(diff>k){
                m[s[low]]--;
                if(m[s[low]]==0) {
                    m.erase(s[low]);
                }
                low++;
                len=high-low+1;
                maxcount=find_max(m);
                diff=len-maxcount;
            }
            len=high-low+1;
            ans=max(len,ans);

        }
        return ans;
    }
};