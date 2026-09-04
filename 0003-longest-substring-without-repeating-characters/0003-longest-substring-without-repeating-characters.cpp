class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = 0;
        unordered_map<int,int> Arr;
        int ans = 0;
        string temp="";
        temp += s[low];
        for (high = 0; high < s.size(); ++high) {
            Arr[s[high]]++;
            while (Arr.size() <(high-low+1)) {
                Arr[s[low]]--;
                if(Arr[s[low]]==0){
                    Arr.erase(s[low]);
                }
                low++;
            }
            int len = high - low+1 ;
            ans = max(len, ans);
        }
            return ans;
    }
};
