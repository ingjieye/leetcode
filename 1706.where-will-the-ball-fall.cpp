class Solution {
public:
    bool goDown(const vector<vector<int>>& grid, int& x, int& y)
    {
        int rowNum = grid.size();
        int columnNum = grid[0].size();
        if ( 0 > x || x >= columnNum || 0 > y || y >= rowNum) {
            return false;
        }

        bool ret = false;
        if (grid[y][x] == 1) {
            //right wall
            if (x + 1 == columnNum) {
                ret = false;
            } else {
                if (grid[y][x+1] == 1) {
                    x++;
                    y++;
                    ret = true;
                } else {
                    ret = false;
                }
            }
        } else {
            //left wall
            if (x == 0) {
                ret = false;
            } else {
                if (grid[y][x-1] == -1) {
                    x--;
                    y++;
                    ret = true;
                } else {
                    ret = false;
                }
            }
        }
        return ret;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ret;
        int rowNum = grid.size();
        int columnNum = grid[0].size();
        ret.resize(columnNum, -2);
        for (int i = 0; i < columnNum; i++) {
            int x = i;
            int y = 0;
            while (goDown(grid, x, y)) {};
            if (y >= rowNum) {
                ret[i] = x;
            } else {
                ret[i] = -1;
            }
        }
        return ret;
    }
};