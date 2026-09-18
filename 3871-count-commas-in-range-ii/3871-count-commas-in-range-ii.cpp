class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end;

            if (n / 1000 < start) {
                end = n;
            } else {
                end = min(n, start * 1000 - 1);
            }
            ans += (end - start + 1) * commas;

            if (n / 1000 < start)
                break;
            start *= 1000;
            commas++;
        }
        return ans;
    }
};