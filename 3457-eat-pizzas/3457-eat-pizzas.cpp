class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();

        int days = n / 4;
        int odd = (days + 1) / 2;
        int even = days / 2;

        long long ans = 0;

        int i = n - 1;

        // odd days:take largest
        for (int j = 0; j < odd; j++) {
            ans += pizzas[i];
            i--;
        }

        // even days:skip largest take second largest
        for (int j = 0; j < even; j++) {
            i--;
            ans += pizzas[i];
            i--;
        }

        return ans;
    }
};