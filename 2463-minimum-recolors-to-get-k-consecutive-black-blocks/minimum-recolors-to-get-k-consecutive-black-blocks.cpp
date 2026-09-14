class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0;
        int r = 0;
        int n = blocks.size();
        int mini = INT_MAX;
        int cnt = 0;
        int bb = 0;
        while(r<n){
            while(r-l<k){
                if(blocks[r] == 'B'){
                    bb++;
                    if(bb == k) return 0;
                }
                r++;
            }
                mini = min(mini , k-bb);
                if(blocks[l] == 'B') bb--;
                l++;
            }

        
        return mini;
    }
};