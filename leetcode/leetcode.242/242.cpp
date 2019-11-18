class Solution {
public:
    bool isAnagram(string s, string t) {
        //count
        if(s.length() != t.length()) return false;
        vector<unsigned int> vc1(26, 0);
        vector<unsigned int> vc2(26, 0);
        for_each(s.begin(), s.end(), [&vc1](char c){vc1[c - 'a']++;});
        for_each(t.begin(), t.end(), [&vc2](char c){vc2[c - 'a']++;});
        if(vc1 == vc2) return true;
        return false;
    }
};
