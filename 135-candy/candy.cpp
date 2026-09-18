class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> arr(ratings.size(), 0);

        arr[0] = 1;

        int n = ratings.size();
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                arr[i] = arr[i - 1] + 1;
            else
                arr[i] = 1;
        }
        int cur = 1;
      int  cnt = max(arr[ratings.size() - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                cur++;
            } else
                cur = 1;
            cnt += max(cur, arr[i]);
        }

        return cnt;
    }
};