// 125. Valid Palindrome

class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        if (s.isEmpty())
            return true;
        return s.equals(new StringBuilder(s).reverse().toString());
    }
}