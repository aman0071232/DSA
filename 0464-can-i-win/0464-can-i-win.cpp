class Solution {
public:
    unordered_map<string, bool> mp;

    bool solve(vector<bool>& used, int currSum, int maxChoosableInteger,
               int desiredTotal,string& state) {
        if (currSum >= desiredTotal)
            return false;
             if (mp.find(state) != mp.end())
            return mp[state];
      
     

        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (used[i])
                continue;
            used[i] = true;
            state[i-1]='1';
            bool result;

            if (currSum + i >= desiredTotal){
                result=true;
            }else{
               result= !solve(used, currSum + i, maxChoosableInteger, desiredTotal,state); 
              
                
            }
            used[i] = false;
            state[i-1]='0';

            if(result)return mp[state]=true;
        }
        return mp[state] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (total < desiredTotal)
            return false;

        if (desiredTotal <= 0)
            return true;

        vector<bool> used(maxChoosableInteger + 1, false);
        string state(maxChoosableInteger,'0');
        return solve(used, 0, maxChoosableInteger, desiredTotal,state);
    }
};