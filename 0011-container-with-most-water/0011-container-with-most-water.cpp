class Solution {
public:
    int maxArea(vector<int>& height) {
       int lp=0;
       int  currwater=0;
       int maxwater=INT_MIN;
       int rp=height.size()-1;
       while(lp<=rp){
          int width=rp-lp;
          int ht=min(height[lp],height[rp]);
           currwater=width*ht;
          maxwater=max(maxwater,currwater);
          if(height[lp]<height[rp]){
            lp++;
          }else{
            rp--;
          }
       }
       return maxwater;
    }
};