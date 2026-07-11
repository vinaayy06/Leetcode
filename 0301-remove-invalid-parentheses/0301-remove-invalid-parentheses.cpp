class Solution {
public:
    vector<string> removeInvalidParentheses(const string& s) {
        vector<string> result;
        remove(s, result, 0, 0, '(', ')');
        
        return result;
    }

private:
    void remove(const string& s,
                vector<string>& result,
                int scanStart,
                int removeStart,
                char openParen,
                char closeParen) {
        int balance = 0;
        for (int i = scanStart; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == openParen) {
                ++balance;
            } else if (s[i] == closeParen) {
                --balance;
            }
            if (balance >= 0) {
                continue;
            }
            for (int j = removeStart; j <= i; ++j) {
                if (s[j] == closeParen &&
                    (j == removeStart || s[j - 1] != closeParen)) {
                    
                    string next =
                        s.substr(0, j) + s.substr(j + 1);

                    remove(next, result, i, j, openParen, closeParen);
                }
            }
            return;
        }
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        if (openParen == '(') {
            remove(reversed, result, 0, 0, ')', '(');
        } else {
            result.push_back(reversed);
        }
    }
};