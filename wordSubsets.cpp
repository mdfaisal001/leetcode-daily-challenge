class Solution
{
    /* all word 2 words must present in a each word of word1, find all chaar isnot possible so count the max freq
    of char , if the maxfreq ==  word1freq its subst;
    algo
       1. find the frequencies of each char in word2;
       2. count the max frequency of the char;
       3. like the way find freq of the each char in word 1;
       4. if the frequency is less than the max freq of word 2;  and mark the flag as false;
       5. add the word in word1 which have a flag = true;
         }*/
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> maxFreq;
        vector<string> result;
        for (auto word : words2)
        {
            unordered_map<char, int> word2_freq;
            for (char c : word)
            {
                word2_freq[c]++;
                maxFreq[c] = max(maxFreq[c], word2_freq[c]);
            }
        }

        for (auto str : words1)
        {
            unordered_map<char, int> word1_freq;
            for (char d : str)
            {
                word1_freq[d]++;
            }
            bool flag = true;
            for (auto pair : maxFreq)
            {
                if (word1_freq[pair.first] < pair.second)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                result.push_back(str);
            }
        }
        return result;
    }
};