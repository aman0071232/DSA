class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi = INT_MIN;
        int product = 1;
        for (int i = 0; i < dimensions.size(); i++) {
            int hypo = dimensions[i][0] * dimensions[i][0] +
                       dimensions[i][1] * dimensions[i][1];
            if (hypo > maxi) {
                maxi = hypo;
                product = dimensions[i][0] * dimensions[i][1];
            } else if (hypo == maxi) {
                product = max(product, dimensions[i][0] * dimensions[i][1]);
            }
        }
        return product;
    }
};