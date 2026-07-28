class Solution {
public:
    int funct(vector<int>& prefSum, int L, int M) {
        int n = prefSum.size();
        int maxLeftSubSum = 0;
        int result = 0; //Max sum

        for(int mEnd = L + M - 1; mEnd < n; mEnd++) {
            int lEnd = mEnd - M;
            int lStartPrev = lEnd - L;

            int mBlockSum = prefSum[mEnd] - prefSum[lEnd];
            int lBlockSum = prefSum[lEnd] - (lStartPrev < 0 ? 0 : prefSum[lStartPrev]);

            maxLeftSubSum = max(maxLeftSubSum, lBlockSum);

            result = max(result, maxLeftSubSum + mBlockSum);
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        return max(funct(prefSum, L, M), funct(prefSum, M, L));

    }
};
