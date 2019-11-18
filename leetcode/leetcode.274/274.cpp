class Solution {
public:
    int hIndex(vector<int>& citations) {
        int H = 0;
        sort(citations.begin(), citations.end());
        for(int i = 0; i < citations.size(); ++i)
        {
            int h = citations.size() - i;
            if(citations[i] >= h) 
            {
                H = h;
                break;
            }
        }
        return H;
    }
};
