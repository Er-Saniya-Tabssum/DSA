class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        unordered_map<int,int> Arr;
        int ans = 0;
        for (high = 0; high < fruits.size(); ++high) {
            Arr[fruits[high]]++;
            while (Arr.size() >2) {
                Arr[fruits[low]]--;
                if(Arr[fruits[low]]==0){
                    Arr.erase(fruits[low]);
                }
                low++;
            }
            int len = high - low+1 ;
            ans = max(len, ans);
        }
            return ans;
    }
};
