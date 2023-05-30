class Solution {
public:
    string reverseVowels(string s) {
        vector<char> rev;
        rev.insert(rev.begin(), s.begin(), s.end());
        int front = 0;
        int back = s.length() - 1;

        while (front < back) {
            // Checking for vowels should use s[front] and s[back], not front and back themselves
            if (isVowel(s[front]) && isVowel(s[back])) {
                swap(rev[front], rev[back]);
                back--;
                front++;
            } else if (isVowel(s[front])) {
                back--;
            } else {
                front++;
            }
        }

        // Convert rev back to string and return it
        return string(rev.begin(), rev.end());
    }

private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
