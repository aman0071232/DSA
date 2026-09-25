class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxlight = *max_element(lights.begin(), lights.end());
        
        int ans = 0;
        for (int time : arrivalTime) {
            int r = time % period;
            int wait = 0;
            if (r >= maxlight) {
                wait = period - r;
            }
            ans = max(ans, wait);
        }
        return ans;
    }
};