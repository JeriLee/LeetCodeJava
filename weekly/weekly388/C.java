class Solution {
    public String[] shortestSubstrings(String[] arr) {
        HashMap<String, Set<Integer>> hashMap = new HashMap<>();

        List<List<String>> sub = new ArrayList<>();

        for(int i = 0; i < arr.length; ++i) {
            String origin = arr[i];
            int len = origin.length();
            var sub2 = new ArrayList<String>();
            sub.add(sub2);
            for(int leni = 1; leni <= len; ++leni) {
                for(int start = 0; start + leni <= len; ++start) {
                    String str = origin.substring(start, leni + start);
                    var idList = hashMap.computeIfAbsent(str, pp -> new HashSet<>());
                    idList.add(i);

                    sub2.add(str);
                }
            }
        }


        var result = new String[arr.length];

        for(int i = 0; i < arr.length; ++i) {
            String best = null;
            for(var subStr : sub.get(i)) {
                if (best != null && best.length() < subStr.length()) break;
                if (hashMap.get(subStr).size() == 1) {
                    if (best == null) {
                        best = subStr;
                    } else {
                        if (less(subStr , best)) {
                            best = subStr;
                        }
                    }
                }
            }

            if (best == null) best = "";
            result[i] = best;
        }
        return result;
    }

    private static boolean less(String a, String b) {
        if (a.length() < b.length()) return true;
        for(int i = 0; i < a.length(); ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                return a.charAt(i) < b.charAt(i);
            }
        }
        return false;
    }
}