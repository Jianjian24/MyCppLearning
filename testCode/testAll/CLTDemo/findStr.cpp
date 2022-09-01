#include "../../../jian.h"

// s = "abc", t = "ahbgdc", return true.
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
}

int main()
{
    string s = "abc", t = "ahbgdc";

    cout << isSubsequence(s, t);
}