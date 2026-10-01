class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i=0 ; i<str.size() ; i++){
             if(str[i]=='(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
             }
             else{
                //closing
                if(st.size()==0){
                    return false;
                }
                if((st.top()=='(' && str[i]==')') || (st.top()=='{' && str[i]=='}') || (st.top()=='[' && str[i] == ']')) {
                    st.pop();
                }else{
                    //no match
                    return false;
                }
             }
        }
        return st.size()==0;  
          }
};