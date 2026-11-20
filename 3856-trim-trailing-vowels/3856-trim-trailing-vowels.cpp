class Solution {
public:
    string trimTrailingVowels(string s) {
   
        while(!s.empty()){
            if(s.back()=='a'|| s.back()=='e'|| s.back()=='i' ||s.back()=='o'||s.back()=='u'){
                
     s.pop_back();
            }else{
                break;
            }
        }
        return s;
    }
};