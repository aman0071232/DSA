class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;

        for (string s : timePoints) {
            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));

            arr.push_back(h * 60 + m);
        }
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }
        mini = min(mini, 1440 - arr.back() + arr[0]);
        return mini;
    }
};