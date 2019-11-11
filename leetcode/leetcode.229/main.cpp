class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int Modea[2] = {0};
        int Modeb[2] = {0};
        for(auto i : nums)
        {
            if(Modea[1] == 0 && Modeb[0] != i)
            {
                Modea[1] = 1;
                Modea[0] = i;
            }
            else if(Modea[0] == i)
            {
                Modea[1]++;
            }
            else if(Modeb[1] == 0)
            {
                Modeb[1] = 1;
                Modeb[0] = i;
            }
            else if(Modeb[0] == i)
            {
                Modeb[1]++;
            }
            else
            {
                Modeb[1]--;
                Modea[1]--;
            }
            //cout << Modea[0] << "  " << Modea[1] << "    " << Modeb[0] << "  " << Modeb[1] << endl;
        }

        vector<int> res;
        Modea[1] = 0;
        Modeb[1] = 0;
        for(auto i : nums)
        {
            if(Modea[0] == i)
            {
                Modea[1]++;
            }
            else if(Modeb[0] == i)
            {
                Modeb[1]++;
            }
        }
        if(Modea[1] > nums.size() / 3) res.push_back(Modea[0]);
        if(Modeb[1] > nums.size() / 3) res.push_back(Modeb[0]);
        return res;
    }
};
