class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;
        vector<string> rows(numRows);
        int currRow = 0;
        bool down = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1)
                down = !down;
            if (down)
                currRow++;
            else
                currRow--;
        }
        string ans = "";
        for (string row : rows) {
            ans += row;
        }
        return ans;
    }
};