class Solution {
public:
bool isVowel(char ch) {
    return std::string("aeiouAEIOU").find(ch) != std::string::npos;
}
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i <= j){
        if(isVowel(s[i]) && isVowel(s[j])) {
            swap(s[i] , s[j]);
            i++;
            j--;
        }
        else if (!isVowel(s[i]) && isVowel(s[j])) i++;
        else j--;
        }
        return s;
    }
};