class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int start = 0, end = 0;
        int l,r;
        for(int i=1; s[i] != '\0' ; i++) {
            l = i-1;
            r = i+1;
            while(l >= 0 && s[r]!='\0') {
                if(s[l]!=s[r]) break;
                l--;
                r++;
            }
            l++;
            r--;
            if(r - l > end - start) {
                end = r;
                start = l;
            }
            l = i-1;
            r = i;
            while(l >= 0 && s[r]!='\0') {
                if(s[l] != s[r]) break;
                l--;
                r++;
            }
            l++;
            r--;
            if(r - l > end - start) {
                end = r;
                start = l;
            }
        }
        string ans;
        for(l = start; l<=end;l++) ans.push_back(s[l]);
        return ans;
    }
};