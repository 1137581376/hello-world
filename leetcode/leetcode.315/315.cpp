class Solution {
public:
    //just exchange idx, no need to change nums [beg, end)
    void mergeSort(const vector<int>& nums, vector<int>::iterator beg, vector<int>::iterator end, vector<int>& count)
    {
        if(end - beg <= 1) return ;
        vector<int>::iterator mid = beg + (end - beg) / 2;
        mergeSort(nums, beg, mid, count);
        mergeSort(nums, mid, end, count);
        vector<int> temp(end - beg);
        vector<int>::iterator tbeg = beg;
        vector<int>::iterator tmid = mid;
        vector<int>::iterator titer = temp.begin();
        while(tmid - beg > 0 && end - mid > 0)
        {
            if(nums[*beg] > nums[*mid])
            {
                for(vector<int>::iterator iter = beg; iter != tmid; ++iter)
                {
                    count[*iter]++;
                }
                *titer = *mid;
                titer++;
                mid++;
            }
            else/* if(nums[*beg] < nums[*mid])*/
            {
                *titer = *beg;
                titer++;
                beg++;
            }/*
            else
            {
                *titer = *beg;
                beg++;
                titer++;
                *titer = *mid;
                mid++;
                titer++;
            }*/
        }
        //
        while(tmid - beg > 0)
        {
            *titer = *beg;
            beg++;
            titer++;
        }
        while(end - mid > 0)
        {
            *titer = *mid;
            mid++;
            titer++;
        }
        std::copy(temp.begin(), temp.end(), tbeg);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> idx(nums.size());
        //construct index for nums
        for(int i = 0; i < nums.size(); ++i)
            idx[i] = i;
        vector<int> count(nums.size(), 0);
        mergeSort(nums, idx.begin(), idx.end(), count);
        return count;
    }
};
