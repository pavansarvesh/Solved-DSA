// 58. Length of Last Word

class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        System.out.println(s);
        int lastSpaceIndex = s.lastIndexOf(' ');
        return s.length() - lastSpaceIndex - 1;
    }
}