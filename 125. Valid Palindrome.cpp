class Solution {
public:
    bool isPalindrome(string s) {
        string k="",l="";
        for(int i=0;i<s.length();i++){
            k+=tolower(s[i]);
        }
        for(int i=0;i<s.length();i++){
            if((k[i]>='a' && k[i]<='z') || isalnum(k[i])){
                l+=k[i];
            }
        }
        if(l.length()==0 || l.length()==1) return 1;

        
        for(int i=0;i<=l.length()/2;i++){
            if(l[i]!=l[l.length()-i-1]) return 0;
        }
       return 1;
    }
    
};