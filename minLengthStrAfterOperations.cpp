class Solution
{
public:
    int minimumLength(string s)
    {
        unordered_map<char, int> map;
        int delcount = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            map[s[i]]++;
        }
        for (auto it : map)
        {
            int freq = it.second;
            delcount += (freq % 2 == 0) ? freq - 2 : freq - 1;
        }
        return n - delcount;
    }
};