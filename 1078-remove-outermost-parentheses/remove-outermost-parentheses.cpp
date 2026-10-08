class Solution {
public:
    string removeOuterParentheses(string s) {
     int cnt = 0;
     string t = "";
     for(auto c:s){
        if(c == '('){
           if(cnt > 0){
            t += c;
           }
            cnt++;
        }
        else {            cnt--;

           if(cnt > 0){
            t += c;
           }
        }
    
     }
     return t;
    }

};