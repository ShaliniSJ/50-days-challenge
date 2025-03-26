class Solution {
public:
    bool helper(int r,int c,int len,vector<vector<char>> &board,string& word){
        if(len == word.size())return true;
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[len] || board[r][c] == '.')return false;
        char ch = board[r][c];
        board[r][c] = '.';
        bool res = helper(r+1,c,len+1,board,word) || helper(r,c+1,len+1,board,word) ||
        helper(r-1,c,len+1,board,word) ||
        helper(r,c-1,len+1,board,word);
        board[r][c] = ch;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c] == word[0]){
                    if(helper(r,c,0,board,word))return true;
                }
            }
        }
        return false;
    }
};