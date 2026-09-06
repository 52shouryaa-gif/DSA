#include <vector>
#include <string>
#include <algorithm> // Required for sort()

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      
        if (strs.empty()) return "";

        string s = "";
        
     
        sort(strs.begin(), strs.end());
        
       
        string first = strs[0];
        string last = strs[strs.size() - 1];
        
      
        for (int i = 0; i < first.size(); i++) {
            if (first[i] == last[i]) {
                s.push_back(first[i]);
            } else {
                break;
            }
        }
        
        return s;
    }
};