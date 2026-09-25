class Solution {
public:
    int arr[10001];
    int helper(int n) {
        int mini = INT_MAX;
        if (n == 0)
            return 0;
        if(arr[n]!=-1)return arr[n];    
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + helper(n - i * i);

            mini = min(mini, result);
        }
        return arr[n]= mini;
    }
    int numSquares(int n) {
        memset(arr, -1, sizeof(arr));
        return helper(n);
    }
};