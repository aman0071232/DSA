class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long f=0;
        long long g=nums[0];

        for(int i=1;i<nums.size();i++){
            if(colors[i]==colors[i-1]){
                long long newG=f+nums[i];
                f=max(f,g);
                g=newG;
            }else{
                long long newG=max(f,g)+nums[i];
                f=max(f,g);
                g=newG;
            }
        }return max(f,g);
    }
};