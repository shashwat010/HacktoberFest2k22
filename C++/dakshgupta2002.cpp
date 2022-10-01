#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution {
public:
    int maxMoves, rows, columns;    
    vector<vector<vector<int>>> dp;

    int spread(int r, int c, int moves){
        if (moves==maxMoves) return 0;
        if (dp[r][c][moves] != -1) return dp[r][c][moves];

        
        int ans = 0, aa=0, bb=0, cc=0, dd=0;

        if (r==0) ans+=1;
        else {aa = spread(r-1, c, moves+1) % MOD;};

        if (r==rows-1) ans+=1;
        else {bb = spread(r+1, c, moves+1) % MOD;};

        if (c==0) ans+=1;
        else {cc = spread(r, c-1, moves+1) % MOD;};

        if (c==columns-1) ans+=1;
        else {dd = spread(r, c+1, moves+1) % MOD;};

        ans = (ans + ((aa+bb)%MOD + (cc+dd)%MOD)%MOD)%MOD;

        return dp[r][c][moves] = ans % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        maxMoves = maxMove;
        rows=m;
        columns=n;

        for (int i=0; i<m; i++){
            vector<vector<int>> rv;
            for (int j=0; j<n; j++){
                vector<int> cv(maxMove, -1);
                rv.push_back(cv);
            }
            dp.push_back(rv);
        }

        return spread(startRow, startColumn, 0);    
    }
};