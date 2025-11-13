// Last updated: 11/13/2025, 1:16:01 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
return (pos == std::string::npos) ? -1 : pos;
        
        
    }
};