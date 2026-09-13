class Solution {
public:
    bool isIsomorphic(string s, string t) {
      map<char , char> mp;
      map<char , char> mpp;
     for(int i = 0 ; i< s.length(); i++){
        if(mp.count(s[i]) && mp[s[i]]!= t[i]) return false;
         if(mpp.count(t[i]) && mpp[t[i]]!= s[i]) return false;
         mp[s[i]] = t[i];
         mpp[t[i]] = s[i];
     }
     return true;

     if(mp.size()==mpp.size()) return true;
     return false;
        
    }
};