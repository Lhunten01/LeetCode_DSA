class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false; // If the lengths are not the same, they cannot be isomorphic.
        }

        unordered_map<char, char> charMap;

        for (int i = 0; i < s.length(); i++) {
            char sChar = s[i];
            char tChar = t[i];

            if (charMap.count(sChar)) {
                if (charMap[sChar] != tChar) {
                    return false;
                }
            } else {
                charMap[sChar] = tChar;
            }
        }

        // Ensure that each tChar is only mapped once
        unordered_set<char> mappedTChars;
        for (const auto& kv : charMap) {
            char tChar = kv.second;
            if (mappedTChars.count(tChar)) {
                return false;
            }
            mappedTChars.insert(tChar);
        }

        return true;
    }
};
