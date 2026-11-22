class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push(map<string, int>());
        int i = 0;
        int n = formula.size();

        while (i < n) {

            if (formula[i] == '(') {
                st.push(map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0)
                    num = 1;

                auto top = st.top();
                st.pop();

                for (auto it : top) {
                    st.top()[it.first] += it.second * num;
                }
            } else {
                string atom = "";

                atom += formula[i];
                i++;
                while (i < n && islower(formula[i])) {
                    atom += formula[i];
                    i++;
                }

                int num = 0;

                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0)
                    num = 1;
                st.top()[atom] += num;
            }
        }
        string ans = "";
        for (auto it : st.top()) {
            ans += it.first;

            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};