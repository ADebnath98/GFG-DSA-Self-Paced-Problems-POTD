//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int x=0, y=0, minx=0, maxx=0, miny=0, maxy=0;
        for(auto ch : s){
            if(ch == 'L'){ y-=1; miny=min(y,miny);}
            if(ch == 'R'){ y+=1; maxy=max(y,maxy);}
            if(ch == 'D'){ x-=1; minx=min(x,minx);}
            if(ch == 'U'){ x+=1; maxx=max(x,maxx);}
        }
        if((n-maxx)-(1-minx) >= 0 and (m-maxy)-(1-miny) >= 0){
            return 1;
        }
        return 0;
 }
};