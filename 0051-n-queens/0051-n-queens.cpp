class Solution {
public:
    unordered_map<int,bool>left;
    unordered_map<int,bool>upper;
    unordered_map<int,bool>lower;

    bool isSafe(vector<string>&board, int row, int col){
        if(left[col] == true || upper[row - col] == true || lower[row + col] == true)
            return false;
        return true;
    }

    void helper(vector<vector<string>>& res,vector<string> &board, int n, int row){
        if(row == n){
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row, col)){
                board[row][col] = 'Q';
                left[col] = true;
                upper[row - col] = true;
                lower[row + col] = true;
                helper(res,board,n,row+1);
                board[row][col] = '.';
                left[col] = false;
                upper[row - col] = false;
                lower[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board;
        string row = "";
        for(int _=0;_ < n;_++)row.push_back('.');
        for(int _=0;_ < n;_++)board.push_back(row);
        helper(res,board,n,0);
        return res;
    }
};