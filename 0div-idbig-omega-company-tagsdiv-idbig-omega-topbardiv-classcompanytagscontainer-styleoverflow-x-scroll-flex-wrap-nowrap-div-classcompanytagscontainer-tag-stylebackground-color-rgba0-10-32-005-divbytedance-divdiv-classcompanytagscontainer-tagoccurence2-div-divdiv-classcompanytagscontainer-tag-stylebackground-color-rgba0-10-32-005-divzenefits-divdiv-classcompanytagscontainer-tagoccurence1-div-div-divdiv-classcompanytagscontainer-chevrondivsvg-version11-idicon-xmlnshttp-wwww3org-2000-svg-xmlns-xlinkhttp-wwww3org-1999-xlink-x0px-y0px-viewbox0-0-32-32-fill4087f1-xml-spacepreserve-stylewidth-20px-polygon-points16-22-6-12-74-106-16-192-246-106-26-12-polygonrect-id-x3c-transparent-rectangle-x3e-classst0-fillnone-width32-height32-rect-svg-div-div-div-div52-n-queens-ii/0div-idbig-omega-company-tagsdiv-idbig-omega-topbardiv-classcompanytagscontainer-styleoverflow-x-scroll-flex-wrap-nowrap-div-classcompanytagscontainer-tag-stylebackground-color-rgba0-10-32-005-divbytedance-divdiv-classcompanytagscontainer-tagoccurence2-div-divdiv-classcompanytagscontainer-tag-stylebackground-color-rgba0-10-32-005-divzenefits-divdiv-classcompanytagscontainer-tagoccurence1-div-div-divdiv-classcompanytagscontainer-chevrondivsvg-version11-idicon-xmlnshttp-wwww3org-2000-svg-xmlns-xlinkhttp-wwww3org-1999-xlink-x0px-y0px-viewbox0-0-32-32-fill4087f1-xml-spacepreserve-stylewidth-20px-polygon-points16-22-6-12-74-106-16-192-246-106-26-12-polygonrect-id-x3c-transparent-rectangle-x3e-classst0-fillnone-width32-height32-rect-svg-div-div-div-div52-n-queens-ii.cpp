class Solution {
public:
    
    bool canPlace ( int x , int col , vector <vector<string>>&ans,  vector <string>& s){
        int row =x;
        int column = col;
      while ( x >= 0 && col >= 0 )
      {       
        if(s[x][col]=='Q')  return false;
        x--;
        col--;      
      }
      x= row;
      col=column;
        
     while ( x <  s.size() && col >= 0 ){
            
            if(s[x][col]=='Q') return false;
            x++;
            col--;
            
            
        }
      x= row;
      col=column; 
       while( col >= 0 ){
          
          if (s[x][col]=='Q') return false;
          col--;
   
      }  
        return true;
    
    }
    
    void solve ( int n,   vector <vector <string> >&ans,  vector <string>&s, int col){
        if (col == n) {
            ans.push_back(s);
            return;
        }

         for ( int row = 0 ; row < n ;row ++){
             if ( canPlace( row, col, ans, s)){
                  s[row][col]='Q';
                 solve( n, ans , s, col+1);
                 //backtrack
                  s[row][col]='.';
             }
         }
    }
    
    
    int totalNQueens(int n) {
        vector <vector <string>> ans;
        vector <string> s ( n, string(n,'.'));
        
        solve ( n, ans , s, 0);
         return ans.size();
    }
};