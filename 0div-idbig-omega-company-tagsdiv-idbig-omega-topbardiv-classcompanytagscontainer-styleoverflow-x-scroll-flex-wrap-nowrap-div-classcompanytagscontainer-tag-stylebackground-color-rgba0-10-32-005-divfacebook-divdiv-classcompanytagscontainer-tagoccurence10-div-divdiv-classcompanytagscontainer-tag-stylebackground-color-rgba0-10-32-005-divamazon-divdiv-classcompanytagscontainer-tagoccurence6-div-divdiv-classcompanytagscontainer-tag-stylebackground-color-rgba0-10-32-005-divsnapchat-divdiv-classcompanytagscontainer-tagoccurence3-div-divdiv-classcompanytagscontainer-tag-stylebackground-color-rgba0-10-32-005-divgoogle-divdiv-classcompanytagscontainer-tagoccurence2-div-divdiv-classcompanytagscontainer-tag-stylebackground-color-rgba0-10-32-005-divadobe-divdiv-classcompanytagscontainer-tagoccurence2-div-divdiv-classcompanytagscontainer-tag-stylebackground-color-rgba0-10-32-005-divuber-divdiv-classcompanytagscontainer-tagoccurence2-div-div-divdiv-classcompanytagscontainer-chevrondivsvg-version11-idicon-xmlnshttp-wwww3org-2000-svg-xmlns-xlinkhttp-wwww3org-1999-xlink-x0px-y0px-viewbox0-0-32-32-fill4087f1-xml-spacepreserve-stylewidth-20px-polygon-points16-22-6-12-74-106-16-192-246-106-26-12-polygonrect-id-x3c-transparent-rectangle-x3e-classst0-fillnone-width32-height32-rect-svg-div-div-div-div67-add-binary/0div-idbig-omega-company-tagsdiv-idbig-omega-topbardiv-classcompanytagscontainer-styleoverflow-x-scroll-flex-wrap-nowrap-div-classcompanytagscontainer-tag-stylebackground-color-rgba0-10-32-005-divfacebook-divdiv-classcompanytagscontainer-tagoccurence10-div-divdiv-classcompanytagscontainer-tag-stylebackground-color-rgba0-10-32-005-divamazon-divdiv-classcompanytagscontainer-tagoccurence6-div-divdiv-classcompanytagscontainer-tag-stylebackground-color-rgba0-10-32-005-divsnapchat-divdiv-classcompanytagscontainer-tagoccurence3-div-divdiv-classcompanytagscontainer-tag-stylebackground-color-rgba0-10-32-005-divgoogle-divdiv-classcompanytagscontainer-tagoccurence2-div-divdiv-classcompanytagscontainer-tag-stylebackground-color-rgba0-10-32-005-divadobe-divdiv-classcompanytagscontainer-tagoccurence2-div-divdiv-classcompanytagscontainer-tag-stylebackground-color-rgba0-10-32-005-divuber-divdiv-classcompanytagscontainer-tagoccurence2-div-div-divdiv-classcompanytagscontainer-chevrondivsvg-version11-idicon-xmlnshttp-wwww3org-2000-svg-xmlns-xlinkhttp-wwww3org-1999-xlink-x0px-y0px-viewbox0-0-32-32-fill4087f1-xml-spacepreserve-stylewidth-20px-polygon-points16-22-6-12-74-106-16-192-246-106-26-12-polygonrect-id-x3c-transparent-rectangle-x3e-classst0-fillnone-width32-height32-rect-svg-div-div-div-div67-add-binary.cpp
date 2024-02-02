class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        int carry = 0;
        int i = 0;
        string ans = "";
        
        while (i < lena || i < lenb || carry != 0) {
            int firstnum = 0;
            if (i < lena && a[lena - i - 1] == '1') {
                firstnum = 1; 
            }
            int secondnum = 0;
            if (i < lenb && b[lenb - i - 1] == '1') {
                secondnum = 1; 
            }
            
            ans = to_string((firstnum + secondnum + carry) % 2) + ans;
            carry = (firstnum + secondnum + carry) / 2;
            i++;
        }
        
        return ans;
    }
};
