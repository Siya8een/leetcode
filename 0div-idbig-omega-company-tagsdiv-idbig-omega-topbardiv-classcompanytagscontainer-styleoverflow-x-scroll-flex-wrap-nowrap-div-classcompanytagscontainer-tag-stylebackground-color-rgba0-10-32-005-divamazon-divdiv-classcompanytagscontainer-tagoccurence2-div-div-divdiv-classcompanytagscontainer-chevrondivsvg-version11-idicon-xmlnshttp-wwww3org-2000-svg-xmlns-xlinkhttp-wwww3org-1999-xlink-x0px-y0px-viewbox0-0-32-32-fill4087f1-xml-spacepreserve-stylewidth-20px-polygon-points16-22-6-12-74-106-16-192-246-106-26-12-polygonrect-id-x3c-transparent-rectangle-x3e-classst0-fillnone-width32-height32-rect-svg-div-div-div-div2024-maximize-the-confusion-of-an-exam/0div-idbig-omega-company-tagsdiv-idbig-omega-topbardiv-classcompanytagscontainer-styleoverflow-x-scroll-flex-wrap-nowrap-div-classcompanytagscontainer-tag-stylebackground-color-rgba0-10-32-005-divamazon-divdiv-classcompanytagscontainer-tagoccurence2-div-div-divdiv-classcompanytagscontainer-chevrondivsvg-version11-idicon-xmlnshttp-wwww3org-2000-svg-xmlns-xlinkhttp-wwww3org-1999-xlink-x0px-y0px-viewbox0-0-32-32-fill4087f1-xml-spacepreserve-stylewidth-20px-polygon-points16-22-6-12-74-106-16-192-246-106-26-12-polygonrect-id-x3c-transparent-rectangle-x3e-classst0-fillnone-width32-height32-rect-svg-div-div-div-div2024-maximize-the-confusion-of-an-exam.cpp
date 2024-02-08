class Solution {
public:
    
    
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n =  answerKey.length();
        int j =0;
        int maxlength1=0;
        int maxlength2=0;
        int countchanged =0;
        // find maxtrueonsecutives
        int i =0;
       while (  i < n){
           if ( answerKey[i]== 'F'){
              countchanged++; 
           }
           while ( countchanged > k){
                if ( answerKey[j]=='F' ){
              countchanged--; 
           }
               j++;
           }
           i++;
           maxlength1 = max ( maxlength1 , i - j);
       }
        cout << maxlength1<< endl;
     countchanged =0;
           j =0;
      i =0;
        // finding maxfalse consecutives 
         while (  i < n){
           if ( answerKey[i]== 'T'){
              countchanged++; 
           }
           while ( countchanged > k){
                if ( answerKey[j]== 'T'){
              countchanged--; 
           }
               j++;
           }
             i++;
           maxlength2 = max ( maxlength2 , i - j);
       }
        cout << maxlength2;
        return max ( maxlength1,maxlength2);
    }
};