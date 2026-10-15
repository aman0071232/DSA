class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); i++) {
            int papers = n - i;
            if (citations[i] >= papers) {
                return papers;
            }
        }
        return 0;
    }
};