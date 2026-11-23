class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> f;
        int count =0;
        for(int i=0;i<text.size();i++){
            f[text[i]]++;
        }
            int B=f['b'];
            int A=f['a'];
            int L =f['l'];
            int O = f['o'];
            int N = f['n'];
            while(B!=0 && A!=0 && L>1 && O>1 && N!=0){
                B--;
                A--;L--;L--;O--;O--;N--;
                count ++;
            }

        return count;
    }
};