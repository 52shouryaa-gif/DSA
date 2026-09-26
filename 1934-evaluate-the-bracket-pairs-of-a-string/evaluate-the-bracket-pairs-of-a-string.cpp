class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string> mpp;
        for(auto& k:knowledge){
        mpp[k[0]] = k[1];
        }
        string ans , key ;
        int ind = false;
        for(char c: s){
            if(c=='('){ ind = true; key = "";}
            else if(c == ')'){ind = false;
            ans += mpp.count(key)?mpp[key]:"?";}
            else if (ind) key += c;
            else ans += c;
        }
        return ans;
    }
};