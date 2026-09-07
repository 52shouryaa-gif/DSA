class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string word;
        int prev = -1;
        while (ss >> word) {
            if (all_of(word.begin(), word.end(), ::isdigit)) {
                int num = stoi(word);
                if (num <= prev) return false;
                prev = num;
            }
        }
        return true;
    }
};