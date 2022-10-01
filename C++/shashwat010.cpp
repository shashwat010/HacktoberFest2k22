class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        if (s.back() == '0'){
            if(s.size() == 1) return 0;
        }else{
            if(s.size() == 1) return 1;
            dp[s.size()-1] = 1;
        }
        
        for(int i = s.size()-2; i >= 0; i--){
            if(s[i] == '0') continue;
            if(stoi(s.substr(i,2)) <= 26){
                if(i == s.size()-2){
                    dp[i] = dp[i+1] + 1;
                }else{
                    dp[i] = dp[i+1] + dp[i+2];
                }
            }else{
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};