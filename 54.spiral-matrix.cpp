class Solution {
public:
    enum Direction
    {
        right,
        down,
        left,
        up
    };

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftMax = 0;
        int topMax = 0;
        int rightMax = matrix[0].size() - 1;
        int buttomMax = matrix.size() - 1;
        
        int x = 0;
        int y = 0;
        auto direction = Direction::right;
        auto steps = matrix.size() * matrix[0].size();

        vector<int> ret;
        ret.reserve(steps);
        while (steps --> 0) {
            ret.push_back(matrix[y][x]);
            if (direction == Direction::right) {
                if (x == rightMax) {
                    direction = Direction::down;
                    topMax++;
                    y++;
                } else {
                    x++;
                }
            } else if (direction == Direction::down) {
                if (y == buttomMax) {
                    direction = Direction::left;
                    rightMax--;
                    x--;
                } else {
                    y++;
                }
            } else if (direction == Direction::left) {
                if (x == leftMax) {
                    direction = Direction::up;
                    buttomMax--;
                    y--;
                } else {
                    x--;
                }
            } else if (direction == Direction::up) {
                if (y == topMax) {
                    direction = Direction::right;
                    leftMax++;
                    x++;
                } else {
                    y--;
                }
            }
        }
        return ret;
    }
};