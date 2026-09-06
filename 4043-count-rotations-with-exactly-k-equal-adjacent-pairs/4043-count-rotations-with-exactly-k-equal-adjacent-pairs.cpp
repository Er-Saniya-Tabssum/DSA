class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int total=0;
        for(int i=0;i<n;i++){
            if(s[i]==s[(i+1)%n]){
                total++;
            }
        }
        int es=total;
        int us=n-total;
        if(k==total-1) return es;
        if(k==total) return us;
        return 0;
    }
};