class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> newShift(n, 0);
        /* difference array concept wiht slight modification [l,r,x]
        In general we add arr[l]+=x and arr[r +1]-=x then do the prfix sum but here we do
        based on the direction thatsit;

        algo
        1.find newShift with difference array concept
        2. find prefix sum along with the char replacement;
        3.char - base gives the difference if we add this difference with shif we know
        how many steps to attain the shift from base
        then add with base gives u the new char
        4. for a and z it excludes 26 so the condition %alphasize + alphasize)%alphasize to
        maintain with in limits.
        as like i already said, if i add new steps with base we can attain the char;
        */
        for (auto val : shifts)
        {
            int start = val[0];
            int end = val[1];
            int direction = val[2];
            if (direction == 1)
            {
                newShift[start]++;
            }
            else
            {
                newShift[start]--;
            }
            if (end + 1 < n)
            {
                if (direction == 1)
                {
                    newShift[end + 1]--;
                }
                else
                {
                    newShift[end + 1]++;
                }
            }
        }
        int base = 'a';
        int alphaSize = 26;
        int currShift = 0;
        for (int i = 0; i < s.size(); i++)
        {
            currShift += newShift[i]; // prefixsum
            int newPos = ((s[i] - base + currShift) % alphaSize + alphaSize) % alphaSize;
            char result = base + newPos;
            s[i] = result;
        }
        return s;
    }
};