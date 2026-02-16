// 168. Excel Sheet Column Title

class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();

        while (columnNumber > 0) {
            // Adjust because Excel is 1-indexed (A=1), but math is 0-indexed
            columnNumber--;

            // Find the character (0-25)
            char c = (char) ('A' + (columnNumber % 26));
            sb.append(c);

            // Move to the next "digit"
            columnNumber /= 26;
        }

        // Characters were added in reverse order (ones place, then tens, etc.)
        return sb.reverse().toString();
    }
}