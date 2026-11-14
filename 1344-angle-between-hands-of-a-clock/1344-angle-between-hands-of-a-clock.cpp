class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle = (hour % 12) * 30 + minutes * 0.5;

        double minuteangle = minutes * 6;

        double angle = abs(hourangle - minuteangle);

        return min(angle, 360 - angle);
    }
};