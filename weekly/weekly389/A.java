class Solution {
    public boolean isSubstringPresent(String s) {
        Set<String> vis = new HashSet<>();
        for(int i = 0; i + 2 <= s.length(); ++i) {
            String sub = s.substring(i, i+2);
            vis.add(sub);
        }

        String str2 = new StringBuilder(s).reverse().toString();

        for(int i = 0; i + 2 <= s.length(); ++i) {
            String sub = str2.substring(i, i+2);
            if (vis.contains(sub)) return true;
        }
        return false;
    }
}