
//20. Valid Parentheses
import java.util.ArrayDeque;

class Solution {
    public boolean isValid(String s) {
        // if (str == null || str.length == 0) return true;
        // if (str.length % 2 != 0) return false;
        if (s.length() == 0) {
            return true;
        } else if (s.length() % 2 != 0) {
            return false;
        }
        ArrayDeque<Character> stack = new ArrayDeque<>();
        // System.out.println(stack.peek());
        for (int i = 0; i < s.length(); i++) {
            if ("{[(".contains(String.valueOf(s.charAt(i)))) {
                stack.push(s.charAt(i));
            } else if ("}])".contains(String.valueOf(s.charAt(i)))) {
                if (stack.peek() == null) {
                    return false;
                }
                if (stack.peek() == '(' && s.charAt(i) == ')') {
                    stack.pop();
                } else if (stack.peek() == '{' && s.charAt(i) == '}') {
                    stack.pop();
                } else if (stack.peek() == '[' && s.charAt(i) == ']') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if (stack.peek() == null) {
            return true;
        } else {
            return false;
        }
    }
}