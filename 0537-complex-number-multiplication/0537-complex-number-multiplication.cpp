class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a, b, c, d;
        char sign;

        stringstream s1(num1), s2(num2);

        s1 >> a >> sign >> b;
        s2 >> c >> sign >> d;

        int real = a * c - b * d;
        int imaginary = a * d + b * c;

        return to_string(real) + "+" + to_string(imaginary) + "i";
    }
};