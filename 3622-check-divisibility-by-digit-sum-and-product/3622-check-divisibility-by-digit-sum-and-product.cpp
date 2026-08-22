class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int ori=n;
        int pro = 1;
        int ld = 0;
        while (n > 0) {
            ld = n % 10;
            sum += ld;
            pro *= ld;
            n = n / 10;
        }
        int sumt = sum + pro;
        if (ori % sumt == 0)
            return true;
        else
            return false;
            
    }
};