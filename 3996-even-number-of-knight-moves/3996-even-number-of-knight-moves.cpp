class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        bool visited[8][8][2] = {};

        queue<tuple<int, int, int>> q;
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]][0] = true;

        while (!q.empty()) {
            auto [x, y, moves] = q.front();
            q.pop();

            if (x == target[0] &&
                y == target[1] &&
                moves % 2 == 0) {
                return true;
            }

            for (int k = 0; k < 8; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                int newMoves = moves + 1;
                int parity = newMoves % 2;

                if (newX >= 0 && newX < 8 &&
                    newY >= 0 && newY < 8 &&
                    !visited[newX][newY][parity]) {

                    visited[newX][newY][parity] = true;
                    q.push({newX, newY, newMoves});
                }
            }
        }

        return false;
    }
};