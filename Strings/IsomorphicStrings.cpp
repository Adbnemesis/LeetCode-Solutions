class Solution {
public:
    bool isIsomorphic(string s, string t) {
     unordered_map<char,char> um1;
        unordered_map<char,char> um2;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(um1.find(s[i])!= um1.end()){
                char c = um1[s[i]];
                if(c!= t[i])return false;
            }else if(um2.find(t[i])!= um2.end()){
                char c = um2[t[i]];
                if(c!= s[i])return false;
            }else{
                um1[s[i]] = t[i];
                um2[t[i]] = s[i];
            }
        }
        return true;
    }
};
