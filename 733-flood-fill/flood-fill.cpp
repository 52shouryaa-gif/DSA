class Solution {
private:
    void df(vector<vector<int>>& image, int del[], int delc[],
            int color, int iniclr, int sr, int sc,
            vector<vector<int>>& ans) {

        ans[sr][sc] = color;

        int n = ans.size();
        int m = ans[0].size();

        for (int i = 0; i < 4; i++) {
            int rt = sr + del[i];
            int ct = sc + delc[i];

            if (rt >= 0 && rt < n && ct >= 0 && ct < m &&
                image[rt][ct] == iniclr && ans[rt][ct] != color) {

                ans[rt][ct] = color;
                df(image, del, delc, color, iniclr, rt, ct, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int iniclr = image[sr][sc];

        if (iniclr == color) return image;

        int del[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        vector<vector<int>> ans = image;

        df(image, del, delc, color, iniclr, sr, sc, ans);

        return ans;
    }
};