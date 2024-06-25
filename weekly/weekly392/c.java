class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        int len = nums.length;

        List<Integer> source = new ArrayList<>(len);

        for (int i = 0; i < len; ++i) {
            source.add(nums[i]);
        }

        Collections.sort(source);

        int midIndex = len / 2;
        int midValue = source.get(midIndex);

        if (k == midValue) return 0;

        if (k > midValue) {
            long need = 0;
            for (int index = midIndex; index < len; ++index) {
                if (source.get(index) < k) {
                    need += k - source.get(index);
                } else break;
            }
            return need;
        } else { // k < midValue
            long need = 0;
            for (int index = midIndex; index >= 0; --index) {
                if (source.get(index) > k) {
                    need += source.get(index) - k;
                } else break;
            }
            return need;
        }
    }
}