//14. Longest Common Prefix
class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Objective 1 : Find the Smallest Word
        String smallWord = strs[0],target="";
        for(int i = 0; i < strs.length; i++){
            if(strs[i].length() < smallWord.length()){
                smallWord = strs[i];
            }
        }
        // Objective 2 : Check for commonality
        for(int i = smallWord.length(); i >= 0; i--) {
            target = smallWord.substring(0,i);
            boolean allContain = true;
            for (String s : strs) {
                if (!s.substring(0,i).contains(target)) {
                    allContain = false;
                    break; // No need to check the rest
                }
            }
            if(allContain){
                break;
            }
        }
        return target;
    }
}