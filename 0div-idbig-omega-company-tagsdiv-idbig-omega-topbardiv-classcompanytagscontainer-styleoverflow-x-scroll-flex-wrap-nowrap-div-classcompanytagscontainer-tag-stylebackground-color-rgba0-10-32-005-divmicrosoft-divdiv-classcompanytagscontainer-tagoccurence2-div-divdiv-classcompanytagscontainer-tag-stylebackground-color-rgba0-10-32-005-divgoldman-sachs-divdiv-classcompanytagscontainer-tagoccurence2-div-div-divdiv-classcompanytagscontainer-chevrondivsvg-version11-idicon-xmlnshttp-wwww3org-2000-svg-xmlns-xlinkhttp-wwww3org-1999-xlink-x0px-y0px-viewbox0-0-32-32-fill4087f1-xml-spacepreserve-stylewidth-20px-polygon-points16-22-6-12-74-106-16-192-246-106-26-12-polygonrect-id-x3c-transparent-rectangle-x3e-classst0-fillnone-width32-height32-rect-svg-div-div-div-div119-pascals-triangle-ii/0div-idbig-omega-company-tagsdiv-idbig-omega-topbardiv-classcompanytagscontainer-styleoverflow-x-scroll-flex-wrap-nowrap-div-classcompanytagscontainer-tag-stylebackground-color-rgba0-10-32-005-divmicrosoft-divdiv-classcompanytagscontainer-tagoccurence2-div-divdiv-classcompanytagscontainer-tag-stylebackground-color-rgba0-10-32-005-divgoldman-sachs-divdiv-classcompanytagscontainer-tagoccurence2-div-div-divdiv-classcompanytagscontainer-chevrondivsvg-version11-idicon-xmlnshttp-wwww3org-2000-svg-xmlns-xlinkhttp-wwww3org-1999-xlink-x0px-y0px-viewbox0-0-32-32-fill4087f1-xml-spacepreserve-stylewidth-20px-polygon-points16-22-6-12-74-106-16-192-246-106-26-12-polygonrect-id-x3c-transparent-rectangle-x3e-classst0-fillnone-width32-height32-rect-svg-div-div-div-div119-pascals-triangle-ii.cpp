class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector < vector < int > > ans(rowIndex+1) ;
         for ( int i =0; i <= rowIndex;i++){
             ans[i].resize(i+1);
             ans[i][0]=ans[i][i]=1;
                 for ( int j =1; j <i;j++){
                     ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                 }
         }
        vector < int> answer (0,( rowIndex,0));
        for ( int i =0; i <rowIndex+1;i++){
            answer.push_back(ans[rowIndex][i]);
        }
        return answer;
    }
};

     
        