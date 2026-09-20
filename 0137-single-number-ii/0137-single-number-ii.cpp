class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int k = 0; k <= 31; k++) {
       
            int countones = 0;
            int temp = (1 << k);
            for (int num : nums) {
                if ((num & temp) == 0) {
                  
                } else {
                    countones++;
                }
            }
            if (countones % 3 == 1) {
                result = (result | temp);
            }
        }
        return result;
    }
};