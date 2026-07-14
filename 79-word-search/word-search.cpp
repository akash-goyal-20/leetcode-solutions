class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int index,
             vector<vector<int>>& vis) {
        if (index == word.size()) {
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        vis[i][j] = 1;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int r = row[k] + i;
            int c = col[k] + j;

            if (r >= 0 && r < m && c >= 0 && c < n && vis[r][c] == 0) {
                if (board[r][c] == word[index]) {
                    if (dfs(r, c, board, word, index + 1, vis)) {
                        vis[i][j]=0;
                        return true;
                    }
                }
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> vis(m, vector<int>(n, 0));
                    if (dfs(i, j, board, word, 1, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};