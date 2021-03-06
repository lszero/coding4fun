class Solution {
public:
    bool check(int x, int y, vector<vector<char>>& board){
        for(int j = 0; j < 9; j++){
            if(j != y && board[x][j] == board[x][y]) return false;
        }
        
        for(int i = 0; i < 9; i++){
            if(i != x && board[i][y] == board[x][y]) return false;
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int a = x/3*3+i, b = y/3*3+j;
                if(a != x && b != y && board[a][b] == board[x][y]) return false;
            }
        }
        return true;
    }

    bool DFS(int x, int y, vector<vector<char>>& board){
        if(x == 9) return true;
        if(y == 9) return DFS(x+1, 0, board);
        if(board[x][y] != '.') return DFS(x, y+1, board);

        for(int i = 1; i <= 9; i++){
            board[x][y] = i + '0';
            if(check(x, y, board) && DFS(x, y+1, board)) return true;
        }
        board[x][y] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        DFS(0, 0, board);
    }
};
