class Solution {
public:
    long long minimumSteps(string s) {
        long long j=0;
        int n=s.size();
       long long count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
              swap(s[i],s[j]);
              count+=i-j;
              j++;
            }
        }
        return count;
    }
};