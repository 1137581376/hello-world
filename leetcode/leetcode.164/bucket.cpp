class Solution {
public:
    class bucket {
    public:
        bool isUsed = false;
        int minValue = numeric_limits<int>::max();
        int maxValue = numeric_limits<int>::min();
    };
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        int minGap = max(1, (maxValue - minValue) / (int)(nums.size() - 1));
        int bucketNum = (maxValue - minValue) / minGap + 1;

        vector<bucket> Bucket(bucketNum);
        for(auto i : nums)
        {
            int idx = (i - minValue) / minGap;
            Bucket[idx].isUsed = true;
            Bucket[idx].minValue = min(i, Bucket[idx].minValue);
            Bucket[idx].maxValue = max(i, Bucket[idx].maxValue);
        }
        int Max = numeric_limits<int>::min();
        int preValue = minValue;
        for(auto i : Bucket)
        {
            if(i.isUsed)
            {
                Max = max(Max, i.minValue - preValue);
                preValue = i.maxValue;
            }
        }
        return Max;
    }
};
