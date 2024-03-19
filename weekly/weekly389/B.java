class Solution {
    public long countSubstrings(String s, char c) {
        long count = 0;
        long prev_count = 0;
        for(int i = 0; i < s.length(); ++i) {
            char char2 = s.charAt(i);
            if (char2 == c)  {
                count += prev_count + 1;
                prev_count += 1;
            }
        }
        return count;
    }
}