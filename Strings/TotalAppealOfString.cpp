class Solution {
public:
   
    long long appealSum(string s) {
       long long int ans = 0;
       long long int cnt = 0;
        long long int cts = 0;
        string abc = "abcdefghijklmnopqrstuvwxyz";
      long long int n = s.length();
      long long int ts = n*(n+1)/2;
        for(int i = 0;i<26;i++){
            for(int j = 0;j<n;j++){
                if(s[j] == abc[i]){
                    cts += cnt*(cnt+1)/2;
                    cnt=0;
                }
                else cnt++;
            }
            cts+=cnt*(cnt+1)/2;
            cnt=0;
            ans = ans + ts-cts;
            cts=0;
        }
    return ans;
    }
};
