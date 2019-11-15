class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //base sort
        if(nums.size() < 2) return 0;//condition one
        int exp = 1;
        const int idx = 10;
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> aux(nums.size());
        while(maxValue / exp)
        {
            vector<int> count(idx, 0);
            for(auto i : nums)//count
                count[(i / exp) % 10]++;
            for(int i = 1; i < count.size(); ++i)//get sequence idx
                count[i] += count[i - 1];
            //cout << count[9] << "  " << nums.size() << endl;
            //sort
            reverse(nums.begin(), nums.end());
            for(auto i : nums)
                aux[--count[(i / exp) % 10]] = i;
            std::copy(aux.begin(), aux.end(), nums.begin());
            exp *= 10;
        }
        //get maxGap
        int Max = -1;
        for(int i = 1; i < nums.size(); ++i)
        {
            Max = max(nums[i] - nums[i - 1], Max); 
        }
        return Max;
    }
};
