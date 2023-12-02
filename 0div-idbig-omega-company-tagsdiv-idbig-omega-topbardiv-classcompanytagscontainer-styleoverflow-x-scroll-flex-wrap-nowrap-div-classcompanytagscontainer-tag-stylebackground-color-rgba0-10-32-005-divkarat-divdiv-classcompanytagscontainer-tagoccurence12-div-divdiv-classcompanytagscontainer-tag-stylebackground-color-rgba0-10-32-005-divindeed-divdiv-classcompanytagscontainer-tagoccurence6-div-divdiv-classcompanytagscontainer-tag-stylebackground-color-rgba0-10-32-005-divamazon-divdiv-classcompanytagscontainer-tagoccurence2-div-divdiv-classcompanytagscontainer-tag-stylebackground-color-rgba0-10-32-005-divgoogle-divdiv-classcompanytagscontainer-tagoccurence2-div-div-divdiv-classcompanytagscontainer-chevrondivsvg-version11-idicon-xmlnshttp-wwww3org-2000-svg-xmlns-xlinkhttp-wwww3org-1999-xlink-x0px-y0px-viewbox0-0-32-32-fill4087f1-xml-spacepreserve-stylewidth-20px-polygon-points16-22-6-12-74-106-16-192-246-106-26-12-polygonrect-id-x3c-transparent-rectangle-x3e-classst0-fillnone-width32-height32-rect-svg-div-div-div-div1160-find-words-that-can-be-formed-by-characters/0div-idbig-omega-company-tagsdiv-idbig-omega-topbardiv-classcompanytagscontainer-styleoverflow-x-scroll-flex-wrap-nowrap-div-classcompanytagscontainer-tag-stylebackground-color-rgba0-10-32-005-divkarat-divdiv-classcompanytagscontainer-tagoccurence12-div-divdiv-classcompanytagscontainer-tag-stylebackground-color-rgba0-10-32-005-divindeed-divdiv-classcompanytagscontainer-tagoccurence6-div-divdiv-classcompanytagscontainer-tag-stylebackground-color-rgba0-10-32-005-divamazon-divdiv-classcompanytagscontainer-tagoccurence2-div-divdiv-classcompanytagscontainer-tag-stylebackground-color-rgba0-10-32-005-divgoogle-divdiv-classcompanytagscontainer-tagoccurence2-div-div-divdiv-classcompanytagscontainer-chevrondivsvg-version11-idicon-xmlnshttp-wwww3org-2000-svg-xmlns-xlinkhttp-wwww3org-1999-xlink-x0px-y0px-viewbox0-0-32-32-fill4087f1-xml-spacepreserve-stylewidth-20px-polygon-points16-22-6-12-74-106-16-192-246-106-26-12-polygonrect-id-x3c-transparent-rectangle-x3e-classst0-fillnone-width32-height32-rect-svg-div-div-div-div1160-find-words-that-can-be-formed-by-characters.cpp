
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        unordered_map<char, int> mpp;

        // Populate the frequency map for characters in 'chars'
        for (int i = 0; i < chars.size(); i++) {
            mpp[chars[i]]++;
        }

        // Iterate through each word in the 'words' vector
        for (int i = 0; i < words.size(); i++) {
            // Create a copy of the frequency map for each word
            unordered_map<char, int> wordFreq = mpp;

            bool flag = true;  // Reset the flag for each word
            int count = 0;

            // Iterate through each character in the current word
            for (int j = 0; j < words[i].size(); j++) {
                // Check if the character is present in the frequency map
                if (wordFreq.find(words[i][j]) != wordFreq.end() && wordFreq[words[i][j]] > 0) {
                    // Decrement the frequency if the character is found
                    wordFreq[words[i][j]]--;
                    count++;
                } else {
                    flag = false;
                    break;
                }
            }

            // If the word is formed using characters from 'chars', add its length to the answer
            if (flag) {
                ans += count;
            }
        }

        return ans;
    }
};
