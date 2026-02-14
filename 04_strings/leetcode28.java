//28. Find the Index of the First Occurrence in a String

class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack.contains(needle) == false) {
            return -1;
        }
        return haystack.indexOf(needle);
    }
}