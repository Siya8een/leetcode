//harekrishna Radhey Radhey
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair < string,int>>q;
        q.push({beginWord, 1});
        //{string ,level}
        int ans = 0;
        unordered_set <string > st(wordList.begin(), wordList.end());
        while ( !q.empty()){
            int s = q.size();
            for ( int i=0; i < s; i++){
                auto first = q.front();
                q.pop();
                string Node = first.first;
                int level = first.second;
                if (Node == endWord){
                    return level;
                }
                for ( int index  =0; index < Node.size();index++){
                    char original =Node[index];
                    for ( char ch = 'a';ch <= 'z';ch++){
                        Node[index]=ch;
                        if ( st.find(Node)!= st.end()){
                            q.push({Node, level+1});
                            st.erase(Node);
                        }
                    }
                    Node[index]= original;
                }
                
            }
        }
        return 0 ;
    }
};