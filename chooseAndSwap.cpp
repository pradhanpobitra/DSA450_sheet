class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        int backf[26] = {0};
        int frontf[26] = {0};
        int i=0;
        while(a[i]!='\0') {
            backf[a[i]-'a']++;
            i++;
        }
        for(i=0; a[i]!='\0' ;i++) {
            bool done = false;
            backf[a[i]-'a']--;
            for(char c = 'a' ; c < a[i] ; c++) {
                if(backf[c-'a'] && !frontf[c-'a']) {
                    char d = a[i];
                    int j=0;
                    while(a[j]!='\0') {
                        if(a[j] == c) a[j] = d;
                        else if(a[j] == d) a[j] = c;
                        j++;
                    }
                    done = true;
                    break;
                }
            }
            if(done) return a;
            frontf[a[i]-'a']++;
        }
        return a;
    }
    
};