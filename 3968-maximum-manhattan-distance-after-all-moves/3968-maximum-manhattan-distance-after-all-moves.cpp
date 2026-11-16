class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, z = 0;
        for (char c : moves) {
            if (c == 'U')
                x++;
            else if (c == 'D')
                x--;
            else if (c == 'R')
                y++;
            else if (c == 'L')
                y--;
            else
                z++;
        }
        return abs(x) + abs(y) + z;
    }
};