class Solution {
public:
    string getPalindrom(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() &&
               s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        return s.substr(left, right - left + 1);
    }
    
    string longestPalindrome(string s) {
        string ret;
        for (auto i = 0; i < s.size(); i++) {
            auto a = getPalindrom(s, i, i);
            auto b = getPalindrom(s, i, i+1);
            if (a.length() > ret.length() || 
                b.length() > ret.length()) {
                ret = a.length() > b.length()? a:b;
            }
        }
        return ret;
    }
};