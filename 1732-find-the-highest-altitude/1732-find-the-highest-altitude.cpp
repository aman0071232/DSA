class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude=0;
        int maxAltitude=0;
         for(int g:gain){
            altitude+=g;
            maxAltitude=max(altitude,maxAltitude);
         }
         return maxAltitude;

    }
};