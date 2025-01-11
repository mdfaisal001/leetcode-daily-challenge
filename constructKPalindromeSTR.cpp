class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return false;
        if (n == k)
            return true;
        vector<char> alphabets(26, 0);
        for (int i = 0; i < n; i++)
        {
            alphabets[s[i] - 'a']++;
        }
        int oddCount = 0;
        int evenCount = 0;
        for (int i = 0; i < alphabets.size(); i++)
        {
            if (alphabets[i] % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
            }
        }
        if (oddCount > k)
            return false;
        return true;
    }
};