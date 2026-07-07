class Solution {
public:
    long long sumAndMultiply(int n) {
       
       long long sum=0;
        long long rev=0;
        while(n>0){
            int ld=n%10;
            if(ld!=0){
                sum+=ld;
                rev=rev*10+ld;
            }
            n=n/10;
        }
        long long num=0;
        while(rev>0){
            num=num*10+rev%10;
            rev/=10;
        }
        return sum*num;
    }
};