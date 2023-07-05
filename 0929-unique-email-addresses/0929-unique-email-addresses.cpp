class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqEmails;
        for(string& email: emails) {
            bool inDomain = false;
            string actEmail;
            int i = 0;
            for(int i = 0; i < email.size(); ) {
                char c = email[i];
                if (inDomain) {
                    actEmail.push_back(c);
                    i++;
                } else {
                    if (c == '@') {
                        actEmail.push_back(c);
                        inDomain = true;
                        i++;
                    } else if (c == '.') {
                        i++;
                    } else if (c == '+') {
                        while(email[i] != '@') {
                            i++;
                        }
                    } else {
                        actEmail.push_back(c);
                        i++;
                    }
                }
            }
            uniqEmails.insert(actEmail);
        }
        return uniqEmails.size();
    }
};