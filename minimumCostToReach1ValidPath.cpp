class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        pq.push({0, {0, 0}});
        cost[0][0] = 0;
        int arr1[4] = {0, 0, 1, -1}; // Row
        int arr2[4] = {1, -1, 0, 0}; // Column

        while (!pq.empty())
        {
            auto cell = pq.top();
            int cst = cell.first;
            int row = cell.second.first;
            int col = cell.second.second;
            pq.pop();
            if (visited[row][col])
                continue;
            visited[row][col] = 1;
            if (row == m - 1 && col == n - 1)
                return cst;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + arr1[i];
                int ncol = col + arr2[i];
                if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n)
                    continue;
                int newCost = (grid[row][col] == i + 1) ? 0 : 1;
                if (!visited[nrow][ncol] && cst + newCost < cost[nrow][ncol])
                {
                    cost[nrow][ncol] = cst + newCost;
                    pq.push({cost[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return 0;
    }
};