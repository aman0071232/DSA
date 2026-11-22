class Solution {
public:
    int mod = 1337;

    int myPow(int a, int k) {
        int ans = 1;

        a %= mod;
        while (k > 0) {
            if (k % 2 == 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            k /= 2;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int i = 0; i < b.size(); i++) {
            ans = (myPow(ans, 10) * myPow(a, b[i])) % mod;
        }
        return ans;
    }
};