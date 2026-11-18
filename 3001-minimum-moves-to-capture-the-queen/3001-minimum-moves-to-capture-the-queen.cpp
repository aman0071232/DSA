class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e) {
            if (!(c == a && min(b, f) < d && d < max(b, f)))
                return 1;
        }
        if (b == f) {
            if (!(d == b && min(a, e) < c && c < max(a, e)))
                return 1;
        }
        if (abs(c - e) == abs(d - f)) {
            if (!(abs(a - e) == abs(b - f) && min(c, e) < a && a < max(c, e) &&
                  min(d, f) < b && b < max(d, f)))
                return 1;
        }
        return 2;
    }
};