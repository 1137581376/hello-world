class Solution {
public:
    static bool cmp(const string& a, const string& b)
    {
        if (a == b) return false;
        string s1 = a + b;
        string s2 = b + a;
        if(s1 >= s2) return true;
        else return false;
    }
    string int2str(int a)
    {
        string t = "";
        if(a == 0) return "0";
        while(a)
        {
            t.push_back((a % 10) + '0');
            a /= 10;
        }
        std::reverse(t.begin(), t.end());
        return t;
    }
    bool isAllZero(const string & a)
    {
        for(auto i : a)
        {
            if(i != '0') return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> Nums(nums.size());
        for(int i = 0; i < nums.size(); ++i) Nums[i] = int2str(nums[i]);
        //cout << "sort before" << endl;
        sort(Nums.begin(), Nums.end(), cmp);
        //cout << "sort after" << endl;
        string temp = "";
        for(auto i : Nums) temp += i;
        return isAllZero(temp) ? "0" : temp;
    }
};
