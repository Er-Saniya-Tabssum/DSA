class Solution {
public:
    bool just_chill(vector<int> v1,vector<int> v2){
        for(int i=0;i<256;i++){
            if(v1[i]<v2[i]){
                return false;
            }
        }
            return true;
    }
    string minWindow(string s, string t) {
        int low=0;
        int high=0;
        int ans=INT_MAX;
        int start=-1;
        if(t.size()>s.size()) return "";
        vector<int> f(256,0);
        vector<int> temp(256,0);
        for(int i=0;i<t.size();i++){
            temp[t[i]]++;
        }
        for(high=0;high<s.size();high++){
            f[s[high]]++;
            while(just_chill(f,temp)){
                int len =high-low+1;
                if(ans>len){
                    ans = len;
                    start=low;
                }
                f[s[low]]--;
                low++;
            }

        }    
        return ans==INT_MAX? "":s.substr(start,ans);
    }
};