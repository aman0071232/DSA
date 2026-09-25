class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        static constexpr size_t N{1000};
        
        static array<uint, N> next;
        static array<array<int, N>, N> dp;
        
        const auto n{nums.size()};
        if (n < 3)
            return 0;
        
        unordered_map<int, uint> first_id{};
        first_id.reserve(n << 1);
        for (size_t i{n - 1}, sz{sizeof(int) * n}; ~i; --i) {
            memset(dp[i].data(), 0, sz);
            auto& j{first_id[nums[i]]};
            if (j == 0)
                j = ~0;
                
            next[i] = exchange(j, i);
        }
  
        int ans{};
        for (size_t i{2}; i != n; ++i) {
            const auto v2{nums[i]};
            auto* dp2{dp[i].data()};
            for (size_t j{1}; j != i; ++j) {
                const auto v0{(static_cast<int64_t>(nums[j]) << 1) - v2};
                if (v0 > INT_MAX || v0 < INT_MIN)
                    continue;
                    
                const auto it{first_id.find(v0)};
                if (it == first_id.end())
                    continue;
                
                int s{};
                const auto* dp0{dp[j].data()};
                for (auto k{it->second}; k < j; k = next[k]) {
                    s += dp0[k] + 1;
                }
                ans += dp2[j] = s;
            }
        }

        return ans;
    }
};