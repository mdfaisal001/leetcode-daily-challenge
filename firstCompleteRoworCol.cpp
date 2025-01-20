class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        unordered_map<int, vector<pair<int, int>>> map;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[mat[i][j]].push_back({i, j});
            }
        }

        vector<int> freqrow(m, 0);
        vector<int> freqcol(n, 0);
        for (int i = 0; i < arr.size(); i++)
        {
            if (map.find(arr[i]) != map.end())
            {
                for (auto pair : map[arr[i]])
                {
                    freqrow[pair.first]++;
                    freqcol[pair.second]++;
                    if (freqrow[pair.first] == n || freqcol[pair.second] == m)
                        return i;
                }
            }
        }
        return 0;
    }
};