/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(vector<vector<int>>& grid,int n, int r, int c){
        bool valid = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[r][c] != grid[r+i][c+j]){
                    valid = false;
                    break;
                }
            }
        }
        if(valid) return new Node(grid[r][c],true,nullptr,nullptr,nullptr,nullptr);
        n /= 2;
        Node* topLeft = dfs(grid, n, r,c);
        Node* topRight = dfs(grid,n,r,c+n);
        Node* bottomLeft = dfs(grid, n, r+n,c);
        Node* bottomRight = dfs(grid,n,r+n,c+n);
        return new Node(grid[r][c],false,topLeft,topRight,bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid,grid.size(),0,0);
    }
};