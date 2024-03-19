class Solution {
    public int minimumDeletions(String word, int k) {
        int keyV[] = new int[26];
        for(int i = 0; i < 26; ++i) keyV[i] = 0;

        for(int i = 0; i < word.length(); ++i) {
            int index = word.charAt(i) - 'a';
            keyV[index]+=1;
        }

        List<Integer> used = new ArrayList<>();
        for(int i = 0; i < 26; ++i) {
            if ( keyV[i] > 0) {
                used.add(keyV[i]);
            }
        }
        used.sort(Integer::compare);

        List<Integer> used2 = new ArrayList<>();
        int sum = 0 ;
        for(int i = 0; i < used.size(); ++i) {
            used2.add(sum += used.get(i));
        }
        used2.add(0);

        int tot = used2.get(used2.size()-2);

        long ans = 1 << 55;

        for(int i = 0; i < used.size(); ++i) {
            int r = upper_bound(used, 0, used.size() - 1, used.get(i) +k + 1);
            int a = used2.get(i-1 >= 0? i-1 : used2.size() + i - 1);
            int b = tot - used2.get(r - 1) - (used.size() - r) * (used.get(i) + k);
            if (ans > a+b) ans = a+b;
        }
        return (int)ans;
    }

    public static int upper_bound(List<Integer> arr, int begin, int end, int tar) {
        if(arr.get(end) < tar) return end + 1;
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            if(arr.get(mid) < tar)
                begin = mid + 1;
            else if(arr.get(mid) >= tar)
                end = mid;
        }
        return begin;
    }

}